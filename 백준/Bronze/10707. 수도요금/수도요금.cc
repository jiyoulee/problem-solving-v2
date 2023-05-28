#include <cstdio>
#include <algorithm>

using namespace std;

int A, B, C, D, P;

int main() {
    /*
     * Input.
     */
    scanf("%d%d%d%d%d", &A, &B, &C, &D, &P);
    
    /*
     * Output.
     */
    printf("%d", min(A * P, B + ((0 >= P - C) ? 0 : D * (P - C))));
    
    return 0;
}