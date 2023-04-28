#include <cstdio>
#include <tuple>
#include <queue>

using namespace std;

constexpr int MAX_N = 1000;
constexpr int MAX_M = 1000;
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};

int N, M, Hx, Hy, Ex, Ey;
int map[1 + MAX_N + 3][1 + MAX_M + 3];
queue<tuple<int,int,int,int>> q;
bool visited[2][1 + MAX_N + 3][1 + MAX_N + 3];

int main() {
    /*
     * Input.
     */
    scanf("%d%d%d%d%d%d", &N, &M, &Hx, &Hy, &Ex, &Ey);

    for (int i = 1; N >= i; ++i) {
        for (int j = 1; M >= j; ++j) {
            scanf("%d", &map[i][j]);
        }
    }

    /*
     * Compute and Output.
     */
    visited[1][Hx][Hy] = true;
    q.emplace(Hx, Hy, 1, 0);

    for (int x, y, is_valid, ts; !q.empty(); ) {
        x = get<0>(q.front());
        y = get<1>(q.front());
        is_valid = get<2>(q.front());
        ts = get<3>(q.front());

        // Check exit condition.
        if (Ex == x && Ey == y) {
            printf("%d", ts);

            return 0;
        }

        // Move.
        q.pop();

        for (int d = 0, nx, ny; 4 > d; ++d) {
            nx = x + dx[d];
            ny = y + dy[d];

            if (1 <= nx && N >= nx && 1 <= ny && M >= ny) {
                if (!map[nx][ny] && !visited[is_valid][nx][ny]) {
                    visited[is_valid][nx][ny] = true;
                    q.emplace(nx, ny, is_valid, ts + 1);
                }
                else if (map[nx][ny] && is_valid && !visited[0][nx][ny]) {
                    visited[0][nx][ny] = true;
                    q.emplace(nx, ny, 0, ts + 1);
                }
            }
        }
    }

    printf("-1");

    return 0;
}