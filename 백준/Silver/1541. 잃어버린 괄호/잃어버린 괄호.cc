#include <cstdio>

using namespace std;

int answer;

int main() {
    /*
     * Input and Compute.
     */
    for (int val, is_valid = 1; -1 != scanf("%d", &val); ) {
        if (is_valid && 0 < val) {
            answer += val;
        }
        else {
            is_valid = 0;
            answer -= (0 < val) ? val : -val;
        }
    }

    /*
     * Output.
     */
    printf("%d", answer);

    return 0;
}