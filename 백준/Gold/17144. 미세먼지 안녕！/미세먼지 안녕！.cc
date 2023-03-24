#include <cstdio>

constexpr int MAX_R = 50;
constexpr int MAX_C = 50;
constexpr int DIV = 5;
constexpr int MAX_DIR = 4;
constexpr int di[] = {-1, 1, 0, 0};
constexpr int dj[] = {0, 0, -1, 1};

int answer;
int N, M, T;
int top, bottom;
int A[1 + MAX_R + 1][1 + MAX_C + 1];
int tmp[1 + MAX_R][1 + MAX_C];

int main() {
    /*
     * Input.
     */
    scanf("%d%d%d", &N, &M, &T);

    for (int i = 0, endm = M + 1; N >= i; ++i) {
        A[i][0] = A[i][endm] = -1;
    }
    for (int j = 0, endn = N + 1; M >= j; ++j) {
        A[0][j] = A[endn][j] = -1;
    }

    for (int i = 1;N >= i; ++i) {
        for (int j = 1; M >= j; ++j) {
            scanf("%d", &A[i][j]);

            if (-1 == A[i][j]) {
                bottom = i;
            }
        }
    }
    top = bottom - 1;

    /*
     * Compute.
     */
    while (T--) {
        /*
         * Spread.
         */
        for (int i = 1, ni, nj, val; N >= i; ++i) {
            for (int j = 1; M >= j; ++j) {
                if (0 < A[i][j]) {
                    val = A[i][j] / DIV;

                    if (val) {
                        for (int d = 0; MAX_DIR > d; ++d) {
                            ni = i + di[d];
                            nj = j + dj[d];

                            if (-1 != A[ni][nj]) {
                                tmp[ni][nj] += val;
                                A[i][j] -= val;
                            }
                        }
                    }
                }
            }
        }

        for (int i = 1; N >= i; ++i) {
            for (int j = 1; M >= j; ++j) {
                A[i][j] += tmp[i][j];
                tmp[i][j] = 0;
            }
        }

        /*
         * Circulate.
         */
        for (int i = top - 1; i; --i) {
            A[i][1] = A[i - 1][1];
        }
        for (int i = bottom + 1; N > i; ++i) {
            A[i][1] = A[i + 1][1];
        }

        for (int j = 1; M > j; ++j) {
            A[1][j] = A[1][j + 1];
            A[N][j] = A[N][j + 1];
        }

        for (int i = 1; top > i; ++i) {
            A[i][M] = A[i + 1][M];
        }
        for (int i = N; bottom < i; --i) {
            A[i][M] = A[i - 1][M];
        }

        for (int j = M; 2 < j; --j) {
            A[top][j] = A[top][j - 1];
            A[bottom][j] = A[bottom][j - 1];
        }

        A[bottom][2] = A[top][2] = 0;
    }


    /*
     * Output.
     */
    for (int i = 1; N >= i; ++i) {
        for (int j = 1; M >= j; ++j) {
            answer += A[i][j];
        }
    }

    printf("%d", answer + 2);

    return 0;
}