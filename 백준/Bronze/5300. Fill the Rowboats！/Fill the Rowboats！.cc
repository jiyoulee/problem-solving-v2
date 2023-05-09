#include <cstdio>

using namespace std;

int N;

int main() {
    /*
     * Input.
     */
    scanf("%d", &N);
    
    /*
     * Output.
     */
    for (int i = 1; N >= i; ++i) {
        printf("%d ", i);
        
        if (0 == i % 6 || N == i) {
            printf("Go! ");
        }
    }
    
    return 0;
}