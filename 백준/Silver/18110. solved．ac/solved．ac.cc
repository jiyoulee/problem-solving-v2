#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

constexpr int MAX_N = 300000;

double answer;
int N;
int A[MAX_N + 10];

int main() {
    /*
     * Input.
     */
    scanf("%d", &N);
    
    for (int i = 0; N > i; ++i) {
        scanf("%d", &A[i]);
        
        answer += A[i];
    }
    
    /*
     * Compute.
     */
    if (N) {
        sort(A, A + N);
    
        for (int i = 0, endi = round(N * 0.15); endi > i; ++i) {
            answer -= A[i];
        }
        for (int i = N - round(N * 0.15); N > i; ++i) {
            answer -= A[i];
        }
        
        answer /= N - 2 * round(N * 0.15);
        answer = round(answer);
    }
    
    /*
     * Output.
     */
    printf("%.0lf", answer);
    
    return 0;
}