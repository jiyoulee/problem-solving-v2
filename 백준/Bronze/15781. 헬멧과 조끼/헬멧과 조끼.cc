#include <cstdio>

using namespace std;

int N, M;
int A, B;

int main() {
    /*
     * Input.
     */
    scanf("%d%d", &N, &M);
    
    /*
     * Compute.
     */
    for (int a; scanf("%d", &a) && N--; ) {
        if (A < a) {
            A = a;
        }
    }
    
    for (int b; scanf("%d", &b) && M--; ) {
        if (B < b) {
            B = b;
        }
    }
    
    /*
     * Output.
     */
    printf("%d", A + B);
    
    return 0;
}