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
        printf("Hello World, Judge %d!\n", i);
    }
    
    return 0;
}