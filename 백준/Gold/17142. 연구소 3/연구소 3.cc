#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

#define EMPTY 0
#define WALL 1
#define VIRUS 2

using namespace std;

constexpr int INF = 1 << 12;
constexpr int MAX_N = 50;
constexpr int MAX_M = 10;
constexpr int MAX_DIR = 4;
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};

int answer = INF;
int N, M;
int cnt;
int map[1 + MAX_N + 1][1 + MAX_N + 1];
bool visited[1 + MAX_N][1 + MAX_N];
vector<pair<int,int>> v_global;
int v_local[MAX_M];

void dfs(int last_picked, int depth);

int main() {
    /*
     * Input.
     */
    scanf("%d%d", &N, &M);

    for (int i = 0, endi = N + 1; N >= i; ++i) {
        map[0][i] = map[i][0] = map[endi][i] = map[i][endi] = WALL;
    }

    cnt = N * N;

    for (int i = 1; N >= i; ++i) {
        for (int j = 1; N >= j; ++j) {
            scanf("%d", &map[i][j]);

            if (map[i][j]) {
                --cnt;

                if (VIRUS == map[i][j]) {
                    v_global.emplace_back(i, j);
                }
            }
        }
    }

    /*
     * Compute.
     */
    dfs(-1, 0);

    /*
     * Output.
     */
    printf("%d", (INF == answer) ? -1 : answer);

    return 0;
}

void dfs(int last_picked, int depth) {
    if (M == depth) {
        int tmp_answer = 0, tmp_cnt = cnt;

        memset(visited, false, sizeof(visited));
        
        queue<pair<int,int>> q;
        
        for (int i = 0; M > i; i++) {
            q.emplace(v_global[v_local[i]].first, v_global[v_local[i]].second);
            visited[v_global[v_local[i]].first][v_global[v_local[i]].second] = true;
        }
        
        for (; !q.empty() && tmp_cnt && tmp_answer < answer; ++tmp_answer) {
            for (int i = 0, nx, ny, endi = q.size(); endi > i && tmp_cnt; ++i) {
                auto [x, y] = q.front();

                q.pop();

                for (int d = 0; MAX_DIR > d; ++d) {
                    nx = x + dx[d];
                    ny = y + dy[d];

                    if (WALL != map[nx][ny] && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        q.emplace(nx, ny);

                        if (!map[nx][ny]) {
                            --tmp_cnt;
                        }
                    }

                    if (!tmp_cnt) {
                        break;
                    }
                }
            }
        }

        if (!tmp_cnt && tmp_answer < answer) {
            answer = tmp_answer;
        }

        return;
    }

    for (int i = last_picked + 1, endi = v_global.size() - M + depth; endi >= i; i++) {
        v_local[depth] = i;

        dfs(i, depth + 1);
    }

    return;
}
