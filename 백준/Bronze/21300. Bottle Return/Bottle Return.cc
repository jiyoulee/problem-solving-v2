#include <cstdio>

using namespace std;

int answer;

int main() {
    /*
     * Input and Compute.
     */
    for (int i = 0, val; 6 > i; ++i) {
        scanf("%d", &val);
        
        answer += 5 * val;
    }
    
    /*
     * Output.
     */
    printf("%d", answer);
    
    return 0;
}