#include <cstdio>
#include <cmath>

using namespace std;

constexpr int MAX_N = 1000;

double answer;
int C, N;
int A[MAX_N + 10];
double tmp;

int main() {
    for (scanf("%d", &C); C--; ) {
        /*
         * Input.
         */
        scanf("%d", &N);
        
        for (int i = 0, val; N > i; i++) {
            scanf("%d", &A[i]);
            
            tmp += A[i];
        }
        
        /*
         * Compute.
         */
        tmp /= N;
    
        for (int i = 0; N > i; ++i) {
            if (tmp < A[i]) {
                ++answer;
            }
        }
        
        /*
         * Output.
         */
        printf("%.3lf%\n", round(answer / N * 100000) / 1000);
        
        /*
         * Reset.
         */
        answer = 0;
        tmp = 0;
    }
    
    return 0;
}