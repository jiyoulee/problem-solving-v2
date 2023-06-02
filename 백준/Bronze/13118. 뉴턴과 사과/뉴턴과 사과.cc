#include <cstdio>

using namespace std;

int answer;
int P[4];
int X;

int main() {
    /*
     * Input.
     */
    for (int i = 0; 4 > i; ++i) {
        scanf("%d", &P[i]);
    }
    
    scanf("%d", &X);
    
    /*
     * Compute.
     */
    for (int i = 0; 4 > i; ++i) {
        if (X == P[i]) {
            answer = i + 1;
            
            break;
        }
    }
    
    /*
     * Output.
     */
    printf("%d", answer);
    
    return 0;
}