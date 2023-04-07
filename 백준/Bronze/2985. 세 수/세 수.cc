#include <cstdio>

using namespace std;

int A, B, C;
char c1 = '=', c2 = '=';

int main() {
    /*
     * Input.
     */
    scanf("%d%d%d", &A, &B, &C);

    /*
     * Compute.
     */
    if (C == A + B) {
        c1 = '+';
    }
    else if (C == A - B) {
        c1 = '-';
    }
    else if (C == A * B) {
        c1 = '*';
    }
    else if (C == A / B) {
        c1 = '/';
    }
    else if (A == B + C) {
        c2 = '+';
    }
    else if (A == B - C) {
        c2 = '-';
    }
    else if (A == B * C) {
        c2 = '*';
    }
    else {
        c2 = '/';
    }

    /*
     * Output.
     */
    printf("%d%c%d%c%d", A, c1, B, c2, C);

    return 0;
}