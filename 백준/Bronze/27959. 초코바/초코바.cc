#include <cstdio>

using namespace std;

int N, M;

int main() {
    /*
     * Input.
     */
    scanf("%d%d", &N, &M);
    
    /*
     * Output.
     */
    printf("%s", (M <= 100 * N) ? "Yes" : "No");
    
    return 0;
}