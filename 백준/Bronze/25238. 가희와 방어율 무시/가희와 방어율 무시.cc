#include <cstdio>

using namespace std;

int A, B;

int main() {
    /*
     * Input.
     */
    scanf("%d%d", &A, &B);
    
    /*
     * Output.
     */
    printf("%d", (100 * 100 <= A * (100 - B)) ? 0 : 1);
    
    return 0;
}