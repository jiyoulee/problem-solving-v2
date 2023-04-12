#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

constexpr int MAX_N = 100;
constexpr int MAX_M = 100;
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};

int answer1, answer2;
int N, M;
int map[MAX_N][MAX_M];
bool visited1[MAX_N][MAX_M];
int visited2[MAX_N][MAX_M];
vector<pair<int,int>> v;

void bfs(int x, int y);

int main() {
    /*
     * Input.
     */
    scanf("%d%d", &N, &M);

    for (int i = 0; N > i; ++i) {
        for (int j = 0; M > j; ++j) {
            scanf("%d", &map[i][j]);
        }
    }

    /*
     * Compute.
     */
    for (int x, y, cnt; true; ) {
        // Check exit condition.
        cnt = 0;

        for (int i = 0; N > i; ++i) {
            for (int j = 0; M > j; ++j) {
                if (map[i][j]) {
                    ++cnt;
                }
            }
        }

        if (!cnt) {
            break;
        }

        // Melt.
        bfs(0, 0);

        // Update time.
        ++answer1;

        for (auto& e : v) {
            map[e.first][e.second] = 0;
            visited2[e.first][e.second] = answer1;
        }
        
        v.clear();
    }

    /*
     * Output.
     */
    for (int i = 0; N > i; ++i) {
        for (int j = 0; M > j; ++j) {
            if (answer1 == visited2[i][j]) {
                ++answer2;
            }
        }
    }

    printf("%d\n%d", answer1, answer2);

    return 0;
}

void bfs(int x, int y) {
    int ret = 0;

    queue<pair<int,int>> q;

    visited1[x][y] = true;
    q.emplace(x, y);

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;

        q.pop();

        for (int d = 0, nx, ny; 4 > d; ++d) {
            nx = x + dx[d];
            ny = y + dy[d];

            if (0 <= nx && N > nx && 0 <= ny && M > ny && !visited1[nx][ny]) {
                visited1[nx][ny] = true;

                if (map[nx][ny]) {
                    v.emplace_back(nx, ny);
                }
                else {
                    q.emplace(nx, ny);
                }
            }
        }
    }

    memset(visited1, false, sizeof(visited1));

    return;
}