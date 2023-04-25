#include <cstdio>
#include <queue>

using namespace std;

constexpr int dx[] = { -1, 0, 1, 0 };
constexpr int dy[] = { 0, 1, 0, -1 };

struct Player {
	int x;
	int y;
	int d;
	int s;
	int g;
} players[1 + 30];

int answer[1 + 30];
int N, M, K;
int players_map[1 + 30][1 + 30];
priority_queue<int> guns_map[1 + 30][1 + 30];

int main() {
	freopen("input.txt", "r", stdin);

	/*
	 * Input.
	 */
	scanf("%d%d%d", &N, &M, &K);

	for (int i = 1, tmp; N >= i; ++i) {
		for (int j = 1; N >= j; ++j) {
			scanf("%d", &tmp);

			if (tmp) {
				guns_map[i][j].emplace(tmp);
			}
		}
	}

	for (int i = 1, x, y, d, s; M >= i; ++i) {
		scanf("%d%d%d%d", &x, &y, &d, &s);

		players_map[x][y] = i;
		players[i].x = x;
		players[i].y = y;
		players[i].d = d;
		players[i].s = s;
	}

	/*
	 * Compute.
	 */
	while (K--) {
		for (int p1 = 1, p2, x, y, d, s, g, winner, loser; M >= p1; p1++) {
			// Step 1.
			players_map[players[p1].x][players[p1].y] = 0;

			d = players[p1].d;
			x = players[p1].x + dx[d];
			y = players[p1].y + dy[d];

			if (1 > x || N < x || 1 > y || N < y) {
				d = (d + 2) % 4;
				x = players[p1].x + dx[d];
				y = players[p1].y + dy[d];
			}

			players[p1].d = d;
			players[p1].x = x;
			players[p1].y = y;

			// Step 2.
			p2 = players_map[x][y];

			if (!p2) {
				// Update player map.
				players_map[x][y] = p1;

				// Update player.
				if (!guns_map[x][y].empty()) {
					if (players[p1].g) {
						guns_map[x][y].emplace(players[p1].g);
					}

					players[p1].g = guns_map[x][y].top();
					guns_map[x][y].pop();
				}
			}
			else {
				// Update answer.
				if ((players[p1].s + players[p1].g > players[p2].s + players[p2].g) || ((players[p1].s + players[p1].g == players[p2].s + players[p2].g) && players[p1].s > players[p2].s)) {
					winner = p1;
					loser = p2;
				}
				else {
					winner = p2;
					loser = p1;
				}

				printf("winner: %d, loser: %d\n", winner, loser);
				for (int i = 1; N >= i; ++i) {
					for (int j = 1; N >= j; ++j) {
						printf("%d ", players_map[i][j]);
					}
					printf("\n");
				}

				players_map[x][y] = winner;
				answer[winner] += (players[winner].s + players[winner].g) - (players[loser].s + players[loser].g);

				// Update loser.
				guns_map[x][y].emplace(players[loser].g);
				players[loser].g = 0;

				for (int i = 0, nx, ny; 4 > i; ++i) {
					printf("%d %d\n", x, y);
					nx = x + dx[(players[loser].d + i) % 4];
					ny = y + dy[(players[loser].d + i) % 4];
					printf("%d %d\n", nx, ny);

					if (nx && N >= nx && ny && N >= ny && !players_map[nx][ny]) {
						// Update players map.
						players_map[nx][ny] = loser;

						// Update player.
						players[loser].x = nx;
						players[loser].y = ny;
						players[loser].d = (players[loser].d + i) % 4;

						if (!guns_map[nx][ny].empty()) {
							if (players[loser].g) {
								guns_map[nx][ny].emplace(players[loser].g);
							}

							players[loser].g = guns_map[nx][ny].top();
							guns_map[nx][ny].pop();
						}

						break;
					}
				}

				// Update winner.
				if (!guns_map[x][y].empty()) {
					if (players[winner].g) {
						guns_map[x][y].emplace(players[winner].g);
					}

					players[winner].g = guns_map[x][y].top();
					guns_map[x][y].pop();
				}
			}
		}

		for (int i = 1; M >= i; ++i) {
			printf("%d %d %d %d %d\n", players[i].x, players[i].y, players[i].d, players[i].s, players[i].g);
		}
		printf("\n");
	}

	/*
	 * Output.
	 */
	for (int i = 1; M >= i; ++i) {
		printf("%d ", answer[i]);
	}

	return 0;
}