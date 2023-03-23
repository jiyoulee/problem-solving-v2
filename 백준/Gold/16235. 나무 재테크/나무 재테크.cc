#include <cstdio>
#include <queue>

using namespace std;

constexpr int MAX_N = 10;
constexpr int MAX_DIR = 8;
constexpr int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
constexpr int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

int answer;
int N, M, K;
int G[1 + MAX_N + 1][1 + MAX_N + 1];
int A[1 + MAX_N + 1][1 + MAX_N];
deque<int> T[1 + MAX_N][1 + MAX_N];
int T5[1 + MAX_N + 1][1 + MAX_N + 1];

int main() {
    /*
     * Input.
     */
    scanf("%d%d%d", &N, &M, &K);

    for (int i = 1; N >= i; ++i) {
        for (int j = 1; N >= j; ++j) {
            scanf("%d", &A[i][j]);

            G[i][j] = 5;
        }
    }

    for (int x, y, z; M--; ) {
        scanf("%d%d%d", &x, &y, &z);

        T[x][y].emplace_back(z);
    }

    /*
     * Compute.
     */
    while (K--) {
        for (int i = 1, k, endk; N >= i; ++i) {
            for (int j = 1; N >= j; ++j) {
                if(T[i][j].size()) {
                    T5[i][j] = 0;

                    for(k = 0, endk = T[i][j].size(); endk > k && G[i][j] >= T[i][j][k]; ++k) {
                        G[i][j] -= T[i][j][k];
                        T[i][j][k]++;

                        if (0 == T[i][j][k] % 5) {
                            ++T5[i][j];
                        }
                    }
                    
                    for (; endk > k; T[i][j].pop_back(), ++k) {
                        G[i][j] += T[i][j].back() >> 1;
                    }
                }

                G[i][j] += A[i][j];
            }
        }

        for (int i = 1, ni, nj; N >= i; ++i) {
            for (int j = 1; N >= j; ++j) {
                for (int k = 0; MAX_DIR > k; ++k) {
                    ni = i + dx[k];
                    nj = j + dy[k];

                    for (int l = 0; T5[ni][nj] > l; ++l) {
                        T[i][j].emplace_front(1);
                    }
                }
            }
        }
    }

    /*
     * Output.
     */
    for (int i = 1; N >= i; ++i) {
        for (int j = 1; N >= j; ++j) {
            answer += T[i][j].size();
        }
    }

    printf("%d", answer);
    
    return 0;
}