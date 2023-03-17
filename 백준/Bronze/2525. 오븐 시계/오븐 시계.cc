#include <cstdio>

using namespace std;

constexpr int MAX_MINUTES = 24 * 60;

int answer;
int A, B, C;

int main() {
    /*
     * Input.
     */
    scanf("%d%d%d", &A, &B, &C);

    /*
     * Compute.
     */
    answer = A * 60 + B + C;

    if (MAX_MINUTES <= answer) {
        answer -= MAX_MINUTES;
    }

    /*
     * Output.
     */
    printf("%d %d", answer / 60, answer % 60);

    return 0;
}