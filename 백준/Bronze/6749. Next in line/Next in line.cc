#include <cstdio>

using namespace std;

int Y, M;

int main() {
    /*
     * Input.
     */
    scanf("%d%d", &Y, &M);
    
    /*
     * Output.
     */
    printf("%d", 2 * M - Y);
    
    return 0;
}