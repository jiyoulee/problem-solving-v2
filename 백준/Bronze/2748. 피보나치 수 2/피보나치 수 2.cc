#include <cstdio>

constexpr int MAX_N = 90;

int N;
long long int dp[1 + MAX_N];

int main() {
    /*
     * Input.
     */
    scanf("%d", &N);
    
    /*
     * Compute.
     */
    dp[1] = 1;
    
    for (int i = 2; N >= i; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    
    /*
     * Output.
     */
    printf("%lld", dp[N]);
    
    return 0;
}