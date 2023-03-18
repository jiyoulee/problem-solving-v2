#include <cstdio>

using namespace std;

constexpr int MAX_N = 50;
constexpr int MAX_M = 50;

int answer = 1;
int N, M;
char G[1 + MAX_N + 1][1 + MAX_M + 1];

int main() {
    /*
     * Input.
     */
    scanf("%d%d", &N, &M);

    for (int i = 1; N >= i; ++i) {
        scanf("%s", G[i] + 1);
    }

    /*
     * Compute.
     */
    for (int i = 1; N >= i && answer <= N - i; ++i) {
        for (int j = 1; M >= j && answer <= M - j; ++j) {
            for (int k = 1; G[i + k][j + k]; ++k) {
                if (G[i][j] == G[i + k][j] && G[i][j] == G[i][j + k] && G[i][j] == G[i + k][j + k]) {
                    if (answer < k + 1) {
                        answer = k + 1;
                    }
                }
            }
        }
    }

    /*
     * Output.
     */
    printf("%d", answer * answer);

    return 0;
}