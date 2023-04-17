#include <cstdio>

using namespace std;

int T, A, B;
int div;

int gcd(int a, int b);

int main() {
    for (scanf("%d", &T); T--; ) {
        /*
         * Input.
         */
        scanf("%d%d", &A, &B);

        /*
         * Compute.
         */
        if (A < B) {
            int tmp = A;
            A = B;
            B = tmp;
        }

        div = gcd(A, B);

        /*
         * Output.
         */
        printf("%d\n", A / div * B);
    }

    return 0;
}

int gcd(int a, int b) {
    if (0 == b) {
        return a;
    }

    return gcd(b, a % b);
}