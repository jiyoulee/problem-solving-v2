#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int MAX_N = 100;
constexpr int INF = 1 << 29;

int N, M;
int dp[1 + MAX_N][1 + MAX_N];

int main() {
    /*
     * Input.
     */
    scanf("%d%d", &N, &M);

    for (int i = 1; N >= i; ++i) {
        for (int j = 1; N >= j; ++j) {
            if (i != j) {
                dp[i][j] = INF;
            }
        }
    }

    for (int a, b, c; M--; ) {
        scanf("%d%d%d", &a, &b, &c);

        dp[a][b] = min(dp[a][b], c);
    }

    /*
     * Compute.
     */
    for (int k = 1; N >= k; ++k) {
        for (int i = 1; N >= i; ++i) {
            for (int j = 1; N >= j; ++j) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    /*
     * Output.
     */
    for (int i = 1; N >= i; ++i) {
        for (int j = 1; N >= j; ++j) {
            printf("%d ", (INF == dp[i][j]) ? 0 : dp[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}