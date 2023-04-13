#include <cstdio>

using namespace std;

constexpr int MAX_A = 1000;

int A, B;
int dp[1 + MAX_A];

int main() {
    /*
     * Preset.
     */
    for (int i = 1, val = 1; MAX_A >= i; ++val) {
        for (int tmp = val; MAX_A >= i && tmp--; ++i) {
            dp[i] = dp[i - 1] + val;
        }
    }

    /*
     * Input.
     */
    scanf("%d%d", &A, &B);

    /*
     * Output.
     */
    printf("%d", dp[B] - dp[A - 1]);

    return 0;
}