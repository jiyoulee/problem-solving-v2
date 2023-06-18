#include <cstdio>
#include <algorithm>

using namespace std;

int L, P, V;

int main() {
    for (int i = 1; ; ++i) {
        /*
         * Input.
         */
        scanf("%d%d%d", &L, &P, &V);
        
        if (!L) {
            break;
        }
        
        /*
         * Compute and Output.
         */
        printf("Case %d: %d\n", i, ((V / P) * L) + min(V % P, L));
    }
    
    return 0;
}