#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int MAX_N = 1000;

int N;
int A[MAX_N];

int main() {
    /*
     * Input.
     */
    scanf("%d", &N);
    
    for (int i = 0; N > i; ++i) {
        scanf("%d", &A[i]);
    }
    
    /*
     * Compute.
     */
    sort(A, A + N);
    
    /*
     * Output.
     */
    for (int i = 0; N > i; ++i) {
        printf("%d\n", A[i]);
    }
    
    return 0;
}