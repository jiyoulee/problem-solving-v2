#include <cstdio>

using namespace std;

int A, B, C, D;

int main() {
    /*
     * Input.
     */
    scanf("%d%d%d%d", &A, &B, &C, &D);
    
    /*
     * Output.
     */
    printf("%d\n%d", (A + B + C + D) / 60, (A + B + C + D) % 60);
    
    return 0;
}