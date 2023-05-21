#include <cstdio>
#include <cmath>

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
    printf("%d", abs((A + D) - (B + C)));
    
    return 0;
}