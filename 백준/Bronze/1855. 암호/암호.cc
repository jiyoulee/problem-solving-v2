#include <cstdio>
#include <cstring>

using namespace std;

constexpr int MAX_STR = 200;

int K, L;
char A[MAX_STR + 1];

int main() {
    /*
     * Input.
     */
    scanf("%d%s", &K, A);

    /*
     * Compute.
     */
    L = strlen(A) / K;

    char B[1 + L][1 + K];

    for (int i = 1, ptr = 0; L >= i; ++i) {
        if (i & 1) {
            for (int j = 1; K >= j; ++j) {
                B[i][j] = A[ptr++];
            }
        }
        else {
            for (int j = K; j; --j) {
                B[i][j] = A[ptr++];
            }
        }
    }

    /*
     * Output.
     */
    for (int i = 1; K >= i; ++i) {
        for (int j = 1; L >= j; ++j) {
            printf("%c", B[j][i]);
        }
    }

    return 0;
}