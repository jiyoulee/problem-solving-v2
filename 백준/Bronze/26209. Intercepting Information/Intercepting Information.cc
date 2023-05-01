#include <cstdio>

using namespace std;

int main() {
    /*
     * Input and Output.
     */
    for (int i = 0, N; 8 > i; ++i) {
        scanf("%d", &N);
        
        if (9 == N) {
            printf("F");
            
            return 0;
        }
    }
    
    printf("S");
    
    return 0;
}