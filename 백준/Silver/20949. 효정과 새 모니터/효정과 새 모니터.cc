#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
vector<pair<int,int>> answer;

int main() {
    /*
     * Input.
     */
    scanf("%d", &N);
    
    for (int i = 1, W, H; N >= i; ++i) {
        scanf("%d%d", &W, &H);
        
        answer.emplace_back(-(pow(W, 2) + pow(H, 2)), i);
    }
    
    /*
     * Compute.
     */
    sort(answer.begin(), answer.end());
    
    /*
     * Output.
     */
    for (auto e : answer) {
        printf("%d\n", e.second);
    }
    
    return 0;
}