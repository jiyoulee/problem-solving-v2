#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int MAX_M = 100;
constexpr int MAX_N = 100;
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};

int answer1;
int answer2[MAX_M *  MAX_N];
int M, N, K;
bool map[MAX_M][MAX_N];

void bfs(int x, int y);

int main() {
    /*
     * Input.
     */
    scanf("%d%d%d", &M, &N, &K);

    for (int x1, y1, x2, y2; K--; ) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

        for (int i = x1; x2 > i; ++i) {
            for (int j = y1; y2 > j; ++j) {
                if (!map[i][j]) {
                    map[i][j] = true;
                }
            }
        }
    }

    /*
     * Compute.
     */
    for (int i = 0; N > i; ++i) {
        for (int j = 0; M > j; ++j) {
            if (!map[i][j]) {
                bfs(i, j);

                ++answer1;
            }
        }
    }

    /*
     * Output.
     */
    printf("%d\n", answer1);

    sort(answer2, answer2 + answer1);

    for (int i = 0; answer1 > i; ++i) {
        printf("%d ", answer2[i]);
    }

    return 0;
}

void bfs(int x, int y) {
    queue<pair<int,int>> q;

    map[x][y] = true;
    q.emplace(x, y);

    for (int nx, ny; !q.empty(); ) {
        x = q.front().first;
        y = q.front().second;

        ++answer2[answer1];
        
        q.pop();

        for (int d = 0; 4 > d; ++d) {
            nx = x + dx[d];
            ny = y + dy[d];

            if (0 <= nx && N > nx && 0 <= ny && M > ny && !map[nx][ny]) {
                map[nx][ny] = true;
                q.emplace(nx, ny);
            }
        }
    }

    return;
}