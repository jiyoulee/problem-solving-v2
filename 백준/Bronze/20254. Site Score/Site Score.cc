#include <cstdio>

using namespace std;

int UR, TR, UO, TO;

int main() {
    /*
     * Input.
     */
    scanf("%d%d%d%d", &UR, &TR, &UO, &TO);
    
    /*
     * Output.
     */
    printf("%d", 56 * UR + 24 * TR + 14 * UO + 6 * TO);
    
    return 0;
}