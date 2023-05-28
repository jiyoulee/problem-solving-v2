#include <string>
#include <vector>
#include <cstring>

using namespace std;

constexpr int DIV = 1000000007;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    bool map[n + 1][m + 1];
    
    memset(map, false, sizeof(map));
    for (auto puddle : puddles) {
        map[puddle[1]][puddle[0]] = true;
    }
    
    int dp[n + 1][m + 1];
    
    memset(dp, 0, sizeof(dp));
    dp[0][1] = 1;
    
    for (int i = 1; n >= i; ++i) {
        for (int j = 1; m >= j; ++j) {
            if (!map[i][j]) {
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % DIV;
            }
        }
    }
    
    return answer = dp[n][m];
}