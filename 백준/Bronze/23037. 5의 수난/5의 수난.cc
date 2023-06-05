#include <cstdio>
#include <cmath>

using namespace std;

int answer;
int N;

int main() {
    /*
     * Input.
     */
    scanf("%d", &N);
    
    /*
     * Compute.
     */
    while (N) {
        answer += pow(N % 10, 5);
        N /= 10;
    }
    
    /*
     * Output.
     */
    printf("%d", answer);
    
    return 0;
}