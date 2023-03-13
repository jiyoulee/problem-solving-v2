#include <cstdio>
#include <tuple>
#include <queue>

using namespace std;

constexpr int MAX_N = 1000;
constexpr int MAX_M = 1000;
constexpr int MAX_MOVES = 4;
constexpr char WALL = '1';
constexpr char GROUND = '0';
constexpr int dx[4] = {-1, 1, 0, 0};
constexpr int dy[4] = {0, 0, -1, 1};

int N, M;
char G[1 + MAX_N + 1][1 + MAX_M + 1];
bool visited[2][1 + MAX_N + 1][1 + MAX_M + 1];
queue<tuple<int,int,bool,int>> q;

int main() {
    /*
     * Input.
     */
    scanf("%d%d", &N, &M);

    for (int i = 1; N >= i; ++i) {
        scanf("%s", G[i] + 1);
    }

    /*
     * Compute.
     */
    visited[1][1][1] = true;
    q.emplace(1, 1, 1, 1);

    while (!q.empty()) {
        auto [x, y, cnt, dist] = q.front();

        if (N == x && M == y) {
            break;
        }
        
        q.pop();

        for (int i = 0, nx, ny; MAX_MOVES > i; ++i) {
            nx = x + dx[i];
            ny = y + dy[i];

            if (cnt) {
                if (WALL == G[nx][ny] && !visited[0][nx][ny]) {
                    visited[0][nx][ny] = true;
                    q.emplace(nx, ny, 0, dist + 1);
                }
                if (GROUND == G[nx][ny] && !visited[1][nx][ny]) {
                    visited[1][nx][ny] = true;
                    q.emplace(nx, ny, 1, dist + 1);
                }
            }
            else {
                if (GROUND == G[nx][ny] && !visited[0][nx][ny]) {
                    visited[0][nx][ny] = true;
                    q.emplace(nx, ny, 0, dist + 1);
                }
            }
        }
    }

    /*
     * Output.
     */
    if (q.empty()) {
        printf("-1");
    }
    else {
        printf("%d", get<3>(q.front()));
    }

    return 0;
}