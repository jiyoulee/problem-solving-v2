#include <cstdio>

using namespace std;

int T, F, S, P, C;

int main() {
    for (int i = 0; 2 > i; ++i) {
        /*
         * Input.
         */
        scanf("%d%d%d%d%d", &T, &F, &S, &P, &C);

        /*
         * Compute.
         */
        printf("%d ", 6 * T + 3 * F + 2 * S + 1 * P + 2 * C);
    }

    return 0;
}