#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

constexpr int MAX_N = 50;
constexpr int di2[] = { -1, -1, 1, 1 };
constexpr int dj2[] = { -1, 1, -1, 1 };

int di1[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dj1[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };

int answer;
int N, M, D, S;
int map[MAX_N][MAX_N];
queue<pair<int,int>> clouds;
bool visited[MAX_N][MAX_N];
int cnt[MAX_N][MAX_N];

int main() {
	/*
	 * Input.
	 */
	scanf("%d%d", &N, &M);

	di1[4] = di1[3] = di1[2] = N - 1;
	dj1[8] = dj1[2] = dj1[1] = N - 1;

	for (int i = 0; N > i; ++i) {
		for (int j = 0; N > j; ++j) {
			scanf("%d", &map[i][j]);
		}
	}

	/*
	 * Compute.
	 */
	clouds.emplace(N - 1, 0);
	clouds.emplace(N - 1, 1);
	clouds.emplace(N - 2, 0);
	clouds.emplace(N - 2, 1);

	while (M--) {
		scanf("%d%d", &D, &S);

		// Step 1, 2.
		for (int k = 0, endk = clouds.size(), ni, nj; endk > k; ++k, clouds.pop()) {
			ni = (clouds.front().first + di1[D] * S) % N;
			nj = (clouds.front().second + dj1[D] * S) % N;
			
			clouds.emplace(ni, nj);

			++map[ni][nj];
		}

		// Step 3, 4-1.
		for (int i, j, ni, nj; !clouds.empty(); clouds.pop()) {
			i = clouds.front().first;
			j = clouds.front().second;

			for (int d = 0; 4 > d; ++d) {
				ni = i + di2[d];
				nj = j + dj2[d];

				if (0 <= ni && N > ni && 0 <= nj && N > nj && map[ni][nj]) {
					++cnt[i][j];
				}
			}

			visited[i][j] = true;
		}

		// Step 4-2, 5.
		for (int i = 0; N > i; ++i) {
			for (int j = 0; N > j; ++j) {
				map[i][j] += cnt[i][j];

				if (2 <= map[i][j] && !visited[i][j]) {
					map[i][j] -= 2;
					clouds.emplace(i, j);
				}
			}
		}

		// Reset.
		memset(visited, false, sizeof(visited));
		memset(cnt, 0, sizeof(cnt));
	}

	/*
	 * Output.
	 */
	for (int i = 0; N > i; ++i) {
		for (int j = 0; N > j; ++j) {
			answer += map[i][j];
		}
	}

	printf("%d", answer);

	return 0;
}