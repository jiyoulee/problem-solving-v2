#include <cstdio>

using namespace std;

int N, T, C, P;

int main() {
    /*
     * Input.
     */
    scanf("%d%d%d%d", &N, &T, &C, &P);
    
    /*
     * Output.
     */
    printf("%d", (N - 1) / T * C * P);
    
    return 0;
}