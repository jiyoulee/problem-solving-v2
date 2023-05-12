#include <cstdio>

using namespace std;

int A, B;

int main() {
    /*
     * Input and Output.
     */
    for (scanf("%d%d", &A, &B); A || B; scanf("%d%d", &A, &B)) {
        printf("%d\n", A + B);
    }
    
    return 0;
}