#include <cstdio>

using namespace std;

int T;

int main() {
    /*
     * Input.
     */
    scanf("%d", &T);
    
    /*
     * Output.
     */
    for (int val; T--; ) {
        scanf("%d", &val);
        
        printf("%d %d\n", val, val);
    }
    
    return 0;
}