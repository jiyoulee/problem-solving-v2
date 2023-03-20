#include <cstdio>

using namespace std;

int A, I;

int main() {
    /*
     * Input.
     */
    scanf("%d%d", &A, &I);

    /*
     * Output.
     */
    printf("%d", A * (I - 1) + 1);

    return 0;
}