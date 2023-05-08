#include <cstdio>
#include <algorithm>

using namespace std;

int A[3];

int main() {
    /*
     * Input.
     */
    scanf("%d%d%d", &A[0], &A[1], &A[2]);
    
    /*
     * Compute.
     */
    sort(A, A + 3);
    
    /*
     * Output.
     */
    printf("%d %d %d", A[0], A[1], A[2]);
    
    return 0;
}