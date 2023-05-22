#include <cstdio>

using namespace std;

int X, Y;

int main() {
    /*
     * Input.
     */
    scanf("%d%d", &X, &Y);
    
    /*
     * Output.
     */
    for (; Y >= X; X += 60) {
        printf("All positions change in year %d\n", X);
    }
    
    return 0;
}