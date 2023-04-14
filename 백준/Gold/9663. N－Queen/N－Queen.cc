#include <cstdio>

using namespace std;

constexpr int MAX_N = 15;

long long int answer;
int N;
bool c[MAX_N];
bool d1[2 * MAX_N];
bool d2[2 * MAX_N];

void dfs(int depth);

int main() {
    /*
     * Input.
     */
    scanf("%d", &N);

    /*
     * Compute.
     */
    dfs(0);

    /*
     * Output.
     */
    printf("%lld", answer);

    return 0;
}

void dfs(int depth) {
    if (N == depth) {
        ++answer;

        return;
    }

    for (int j = 0; N > j; ++j) {
        if (!c[j] && !d1[depth - j + N] && !d2[depth + j]) {
            c[j] = true;
            d1[depth - j + N] = true;
            d2[depth + j] = true;

            dfs(depth + 1);

            d2[depth + j] = false;
            d1[depth - j + N] = false;
            c[j] = false;
        }
    }

    return;
}