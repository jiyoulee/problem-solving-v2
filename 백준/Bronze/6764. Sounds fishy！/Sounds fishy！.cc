#include <cstdio>

using namespace std;

int D1, D2, D3, D4;

int main() {
    /*
     * Input.
     */
    scanf("%d%d%d%d", &D1, &D2, &D3, &D4);
    
    /*
     * Output.
     */
    if (D1 < D2 && D2 < D3 && D3 < D4) {
        printf("Fish Rising");
    }
    else if (D1 > D2 && D2 > D3 && D3 > D4) {
        printf("Fish Diving");
    }
    else if (D1 == D2 && D2 == D3 && D3 == D4) {
        printf("Fish At Constant Depth");
    }
    else {
        printf("No Fish");
    }
    
    return 0;
}