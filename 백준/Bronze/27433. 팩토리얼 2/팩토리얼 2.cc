#include <cstdio>

using namespace std;

long long int answer = 1;
int N;

int main() {
    /*
     * Input.
     */
    scanf("%d", &N);
    
    /*
     * Compute.
     */
    for (int i = 2; N >= i; ++i) {
        answer *= i;
    }
    
    /*
     * Output.
     */
    printf("%lld", answer);
    
    return 0;
}