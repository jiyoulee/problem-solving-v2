#include <cstdio>
#include <vector>

using namespace std;

constexpr int MAX_N = 500000;

int N, K, M;
char str[MAX_N + 1 + 10];
vector<char> v;

int main() {
    /*
     * Input.
     */
    scanf("%d%d%s", &N, &K, str);

    M = N - K;

    /*
     * Compute.
     */
    for (int i = 0; N > i; ++i) {
        for (; !v.empty() && 0 < K && v.back() < str[i]; v.pop_back(), K--) {}

        v.emplace_back(str[i]);
    }

    /*
     * Output.
     */
    for (int i = 0; M > i; ++i) {
        printf("%c", v[i]);
    }

    return 0;
}