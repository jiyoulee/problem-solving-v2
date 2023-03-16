// 13:59 [START]
// 14:06 Get minimum. -> Sort, then greedy.
// 14:22 [WA] -> Fix B range upon reset.
// 14:23 [WA] -> Fix F range upon reset.
// 14:30 [AC]

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int MIN_INF = -30000;
constexpr int MAX_INF = 30000;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    /*
     * Compute.
     */
    sort(routes.begin(), routes.end());
    
    int B = MIN_INF, F = MAX_INF;
    
    for (auto& route : routes) {
        int b = route[0], f = route[1];
        
        if (F < b) {
            ++answer;
            
            B = b;
            F = f;
        }
        else {
            B = max(B, b);
            F = min(F, f);
        }
    }
    
    /*
     * Output.
     */
    return answer + 1;
}