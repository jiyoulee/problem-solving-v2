#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int MAX_N = 100;

int N, M;
int A[MAX_N + 1];

int main() {
    /*
     * Input.
     */
    scanf("%d%d", &N, &M);
    
    /*
     * Compute.
     */
    for (int i = 1; N >= i; ++i) {
        A[i] = i;
    }
    
    for (int i = 1, I, J; M >= i; ++i) {
        scanf("%d%d", &I, &J);
        
        swap(A[I], A[J]);
    }
    
    /*
     * Output.
     */
    for (int i = 1; N >= i; ++i) {
        printf("%d ", A[i]);
    }
    
    return 0;
}