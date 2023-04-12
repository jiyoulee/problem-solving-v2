#include <cstdio>

using namespace std;

int N, F;

int main() {
    /*
     * Input.
     */
    scanf("%d%d", &N, &F);

    /*
     * Compute and Output.
     */
    N = N / 100 * 100;

    for (int endN = N + 100; endN > N; ++N) {
        if (0 == N % F) {
            if (10 > N % 100) {
                printf("0%d", N % 100);
            }
            else {
                printf("%d", N % 100);
            }

            break;
        }
    }

    return 0;
}