#include <cstdio>

using namespace std;

int A, B, C;

int main() {
    /*
     * Input.
     */
    scanf("%d%d%d", &A, &B, &C);

    /*
     * Output.
     */
    printf("%d", (B / A) * 3 * C);

    return 0;
}