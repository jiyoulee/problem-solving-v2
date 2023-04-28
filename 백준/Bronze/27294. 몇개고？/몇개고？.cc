#include <cstdio>

using namespace std;

int T, S;

int main() {
    /*
     * Input.
     */
    scanf("%d%d", &T, &S);

    /*
     * Output.
     */
    printf("%d", (!S && 12 <= T && 16 >= T) ? 320 : 280);

    return 0;
}