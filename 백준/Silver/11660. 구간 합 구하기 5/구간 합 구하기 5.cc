#include <cstdio>

using namespace std;

constexpr int MAX_N = 1 << 10;

int N, M;
int dp[1 + MAX_N][1 + MAX_N];

int main() {
    /*
     * Input and Compute.
     */
    scanf("%d%d", &N, &M);

    for (int i = 1; N >= i; ++i) {
        for (int j = 1; N >= j; ++j) {
            scanf("%d", &dp[i][j]);

            dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }

    /*
     * Output.
     */
    for (int x1, y1, x2, y2; M--; ) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

        printf("%d\n", dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1]);
    }

    return 0;
}