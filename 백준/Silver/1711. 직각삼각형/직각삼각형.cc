#include <cstdio>

using namespace std;

constexpr int MAX_N = 1500;
constexpr int MAX_DEPTH = 3;

struct Coordinates {
    long long int x;
    long long int y;
};

int answer;
int N;
Coordinates tmp[MAX_DEPTH];
Coordinates C[MAX_N];

void go(int start, int depth);

int main() {
    /*
     * Input.
     */
    scanf("%d", &N);

    for (int i = 0; N > i; ++i) {
        scanf("%lld%lld", &C[i].x, &C[i].y);
    }

    /*
     * Compute.
     */
    go(0, 0);

    /*
     * Output.
     */
    printf("%d", answer);

    return 0;
}

void go(int start, int depth) {
    if (MAX_DEPTH == depth) {
        long long int ip0 = (tmp[1].x - tmp[0].x) * (tmp[2].x - tmp[0].x) + (tmp[1].y - tmp[0].y) * (tmp[2].y - tmp[0].y);
        long long int ip1 = (tmp[0].x - tmp[1].x) * (tmp[2].x - tmp[1].x) + (tmp[0].y - tmp[1].y) * (tmp[2].y - tmp[1].y);
        long long int ip2 = (tmp[0].x - tmp[2].x) * (tmp[1].x - tmp[2].x) + (tmp[0].y - tmp[2].y) * (tmp[1].y - tmp[2].y);

        if (0 == ip0 || 0 == ip1 || 0 == ip2) {
            ++answer;
        }

        return;
    }

    for (int i = start, endi = N - MAX_DEPTH + depth; endi >= i; ++i) {
        tmp[depth] = C[i];

        go(i + 1, depth + 1);
    }

    return;
}