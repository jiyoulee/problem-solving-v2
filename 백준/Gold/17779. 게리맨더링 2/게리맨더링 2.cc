#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int INF = 1 << 20;
constexpr int MAX_N = 20;

int answer = INF;
int N;
int sum;
int map[1 + MAX_N][1 + MAX_N];

int main() {
    /*
     * Input.
     */
    scanf("%d", &N);

    for (int i = 1; N >= i; ++i) {
        for (int j = 1; N >= j; ++j) {
            scanf("%d", &map[i][j]);

            map[i][j] += map[i][j - 1];
        }

        sum += map[i][N];
    }

    /*
     * Compute.
     */
    for (int i = 1; N >= i; ++i) {
        for (int j = 1; N >= j; ++j) {
            for (int d1 = 1; (1 <= j - d1); ++d1) {
                for (int d2 = 1; (N >= i + d1 + d2) && (N >= j + d2); ++d2) {
                    int cnt[6] = {0, 0, 0, 0, 0, sum};

                    // Area 1 & 2.
                    for (int r = 1; i > r; ++r) {
                        cnt[1] += map[r][j];
                        cnt[2] += map[r][N] - map[r][j];
                    }

                    for (int r = i, endr = i + d1, c = j - 1; endr > r; ++r, --c) {
                        cnt[1] += map[r][c];
                    }

                    for (int r = i, endr = i + d2, c = j; endr >= r; ++r, ++c) {
                        cnt[2] += map[r][N] - map[r][c];
                    }

                    // Area 3 & 4.
                    for (int r = i + d1 + d2 + 1; N >= r; ++r) {
                        cnt[3] += map[r][j - d1 + d2 - 1];
                        cnt[4] += map[r][N] - map[r][j - d1 + d2 - 1];
                    }

                    for (int r = i + d1, endr = i + d1 + d2, c = j - d1 - 1; endr >= r; ++r, ++c) {
                        cnt[3] += map[r][c];
                    }

                    for (int r = i + d2 + 1, endr = i + d1 + d2, c = j + d2 - 1; endr >= r; ++r, --c) {
                        cnt[4] += map[r][N] - map[r][c];
                    }

                    // Area 5.
                    cnt[5] -= cnt[1] + cnt[2] + cnt[3] + cnt[4];

                    // Sort.
                    sort(cnt + 1, cnt + 6);

                    // Update answer.
                    if (cnt[5] - cnt[1] < answer) {
                        answer = cnt[5] - cnt[1];
                    }
                }
            }
        }
    }

    /*
     * Output.
     */
    printf("%d", answer);

    return 0;
}