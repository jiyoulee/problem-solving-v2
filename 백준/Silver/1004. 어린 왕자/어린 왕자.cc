#include <cstdio>
#include <cmath>

using namespace std;

int answer;
int T;
int X1, Y1, X2, Y2, N, CX, CY, R;
long long int tmp1, tmp2;

int main() {
    for (scanf("%d", &T); T--; ) {
        /*
         * Input and Compute.
         */
        scanf("%d%d%d%d%d", &X1, &Y1, &X2, &Y2, &N);

        for (int i = 0; N > i; ++i) {
            scanf("%d%d%d", &CX, &CY, &R);

            tmp1 = pow(X1 - CX, 2) + pow(Y1 - CY, 2) - pow(R, 2);
            tmp2 = pow(X2 - CX, 2) + pow(Y2 - CY, 2) - pow(R, 2);

            if (0 > tmp1 * tmp2) {
                ++answer;
            }
        }

        /*
         * Output.
         */
        printf("%d\n", answer);

        /*
         * Reset.
         */
        answer = 0;
    }
    
    return 0;
}