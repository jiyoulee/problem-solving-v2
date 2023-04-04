#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

constexpr int MAX_N = 50;
constexpr int MAX_M = 50;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, 1, 0 };

int N, M, T, X, D, K;
deque<int> arr[1 + MAX_N + 1];
int sum;
double cnt, avg;
bool visited[1 + MAX_N + 1][1 + MAX_M + 1];
queue<pair<int, int>> q;
bool is_valid;

int main(void) {
    /*
     * Input.
     */
    scanf("%d%d%d", &N, &M, &T);

    cnt = N * M;
    dy[3] = M - 1;
    for (int i = 0, endi = N + 1; M > i; ++i) {
        arr[0].emplace_back(0);
        arr[endi].emplace_back(0);
    }

    for (int i = 1, val; N >= i; ++i) {
        for (int j = 0; M > j; ++j) {
            scanf("%d", &val);

            arr[i].emplace_back(val);
            sum += val;
        }
    }

    /*
     * Compute.
     */
    while (T-- && cnt) {
        scanf("%d%d%d", &X, &D, &K);

        // Rotate circles.
        for (int i = X; N >= i; i += X) {
            for (int j = 1; K >= j; ++j) {
                if (0 == D) {
                    arr[i].emplace_front(arr[i].back());
                    arr[i].pop_back();
                }
                else {
                    arr[i].emplace_back(arr[i].front());
                    arr[i].pop_front();
                }
            }
        }

        // Delete numbers.
        for (int i = 1, local_cnt; N >= i; ++i) {
            for (int j = 0; M > j; ++j) {
                if (arr[i][j] && !visited[i][j]) {
                    local_cnt = 0;

                    visited[i][j] = true;
                    q.emplace(i, j);

                    for (int x, y, nx, ny; !q.empty(); ++local_cnt) {
                        x = q.front().first;
                        y = q.front().second;

                        q.pop();

                        for (int d = 0; 4 > d; ++d) {
                            nx = x + dx[d];
                            ny = (y + dy[d]) % M;

                            if (!visited[nx][ny] && arr[i][j] == arr[nx][ny]) {
                                arr[nx][ny] = 0;
                                visited[nx][ny] = true;

                                q.emplace(nx, ny);
                            }
                        }
                    }

                    if (2 <= local_cnt) {
                        is_valid = true;

                        sum -= arr[i][j] * local_cnt;
                        cnt -= local_cnt;

                        arr[i][j] = 0;
                    }
                }
            }
        }

        // Update numbers.
        if (!is_valid) {
            avg = sum / cnt;

            for (int i = 1; N >= i; ++i) {
                for (int j = 0; M > j; ++j) {
                    if (arr[i][j]) {
                        if (avg < arr[i][j]) {
                            --arr[i][j];
                            --sum;
                        }
                        else if (avg > arr[i][j]) {
                            ++arr[i][j];
                            ++sum;
                        }
                    }
                }
            }
        }

        // Reset.
        memset(visited, false, sizeof(visited));
        is_valid = false;
    }

    /*
     * Output.
     */
    printf("%d", sum);

    return 0;
}