#include <cstdio>
#include <tuple>
#include <vector>
#include <queue>

using namespace std;

constexpr char JIHUN = 'J';
constexpr char FIRE = 'F';
constexpr char EMPTY = '.';
constexpr int MAX_R = 1000;
constexpr int MAX_C = 1000;
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};

int R, C;
char map[MAX_R + 1][MAX_C + 1];
queue<tuple<int,int,int>> q1;
queue<pair<int,int>> q2;

int main() {
    /*
     * Input.
     */
    scanf("%d%d", &R, &C);

    for (int i = 0; R > i; ++i) {
        scanf("%s", map[i]);
    }

    for (int i = 0; R > i; ++i) {
        for (int j = 0; C > j; ++j) {
            if (JIHUN == map[i][j]) {
                q1.emplace(i, j, 1);
            }
            else if (FIRE == map[i][j]) {
                q2.emplace(i, j);
            }
        }
    }

    /*
     * Compute and Output.
     */
    while (true) {
        // Move Jihun.
        for (int endi = q1.size(), x, y, ts; endi--; ) {
            x = get<0>(q1.front());
            y = get<1>(q1.front());
            ts = get<2>(q1.front());

            q1.pop();

            if (JIHUN == map[x][y]) {
                // Check exit condition.
                for (int d = 0, nx, ny; 4 > d; ++d) {
                    nx = x + dx[d];
                    ny = y + dy[d];

                    if (0 > nx || R <= nx || 0 > ny || C <= ny) {
                        printf("%d", ts);

                        return 0;
                    }
                }

                // Continue.
                for (int d = 0, nx, ny; 4 > d; ++d) {
                    nx = x + dx[d];
                    ny = y + dy[d];

                    if (0 <= nx && R > nx && 0 <= ny && C > ny && EMPTY == map[nx][ny]) {
                        map[nx][ny] = JIHUN;
                        q1.emplace(nx, ny, ts + 1);
                    }
                }
            }
        }

        // Move fire.
        // Check exit condition.
        if (!q1.size()) {
            printf("IMPOSSIBLE");

            return 0;
        }

        // Continue.
        for (int endi = q2.size(), x, y; endi--; ) {
            x = q2.front().first;
            y = q2.front().second;

            q2.pop();

            for (int d = 0, nx, ny; 4 > d; ++d) {
                nx = x + dx[d];
                ny = y + dy[d];

                if (0 <= nx && R > nx && 0 <= ny && C > ny && (EMPTY == map[nx][ny] || JIHUN == map[nx][ny])) {
                    map[nx][ny] = FIRE;
                    q2.emplace(nx, ny);
                }
            }
        }
    }

    return 0;
}