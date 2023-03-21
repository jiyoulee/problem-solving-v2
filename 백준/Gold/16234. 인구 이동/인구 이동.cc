#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

constexpr int MAX_N = 50;
constexpr int dx[4] = {-1, 1, 0, 0};
constexpr int dy[4] = {0, 0, -1, 1};

int answer;
int N, L, R;
int A[1 + MAX_N][1 + MAX_N];
bool visited[1 + MAX_N][1 + MAX_N];

int main() {
    /*
     * Input.
     */
    scanf("%d%d%d", &N, &L, &R);

    for (int i = 1; N >= i; ++i) {
        for (int j = 1; N >= j; ++j) {
            scanf("%d", &A[i][j]);
        }
    }

    /*
     * Compute.
     */
    for (; true; ++answer) {
        bool is_valid = false;

        for (int i = 1; N >= i; ++i) {
            for (int j = 1; N >= j; ++j) {
                if (!visited[i][j]) {
                    int cnt = 1;
                    int sum = A[i][j];

                    queue<pair<int,int>> q;
                    vector<pair<int,int>> v;

                    q.emplace(i, j);
                    v.emplace_back(i, j);
                    visited[i][j] = true;

                    while (!q.empty()) {
                        auto [x, y] = q.front();

                        q.pop();

                        for (int k = 0, nx, ny, diff; 4 > k; ++k) {
                            nx = x + dx[k];
                            ny = y + dy[k];

                            if (nx && N >= nx && ny && N >= ny && !visited[nx][ny]) {
                                diff = abs(A[x][y] - A[nx][ny]);

                                if (L <= diff && R >= diff) {
                                    ++cnt;
                                    sum += A[nx][ny];

                                    q.emplace(nx, ny);
                                    v.emplace_back(nx, ny);
                                    visited[nx][ny] = true;
                                }
                            } 
                        }
                    }

                    if (1 < cnt) {
                        is_valid = true;

                        int val = sum / cnt;

                        for (auto& e : v) {
                            A[e.first][e.second] = val;
                        }
                    }
                }
            }
        }

        if (!is_valid) {
            break;
        }

        memset(visited, false, sizeof(visited));
    }

    /*
     * Output.
     */
    printf("%d", answer);

    return 0;
}