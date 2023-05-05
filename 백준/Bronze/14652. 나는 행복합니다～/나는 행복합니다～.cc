#include <cstdio>

using namespace std;

int N, M, K;

int main() {
    /*
     * Input.
     */
    scanf("%d%d%d", &N, &M, &K);
    
    /*
     * Output.
     */
    printf("%d %d", K / M, K % M);
    
    return 0;
}