#include <cstdio>

using namespace std;

int answer = 1;
int N;

int main() {
    /*
     * Input.
     */
    scanf("%d", &N);
    
    /*
     * Output.
     */
    for (; true; ++answer) {
        if (N < answer * answer) {
            break;
        }
    }
    
    printf("The largest square has side length %d.", answer - 1);
    
    return 0;
}