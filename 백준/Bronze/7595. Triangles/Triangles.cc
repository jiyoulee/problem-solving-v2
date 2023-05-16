#include <cstdio>

using namespace std;

int N;

int main() {
    /*
     * Input and Output.
     */
    for (scanf("%d", &N); N; scanf("%d", &N)) {
        for (int i = 1; N >= i; ++i) {
            for (int j = 1; i >= j; ++j) {
                printf("*");
            }
            printf("\n");
        }
    }
    
    return 0;
}