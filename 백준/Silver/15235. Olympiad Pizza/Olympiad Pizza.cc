#include <cstdio>
#include <queue>

using namespace std;

constexpr int MAX_N = 1000;

int answer[1 + MAX_N];
int N;
queue<pair<int,int>> q;

int main() {
    /*
     * Input.
     */
    scanf("%d", &N);

    for (int i = 0, tmp; N > i; ++i) {
        scanf("%d", &tmp);

        q.emplace(tmp, i);
    }

    /*
     * Compute.
     */
    for (int ts = 1; !q.empty(); q.pop(), ++ts) {
        if (1 == q.front().first) {
            answer[q.front().second] = ts;
        }
        else {
            q.emplace(q.front().first - 1, q.front().second);
        }
    }

    /*
     * Output.
     */
    for (int i = 0; N > i; ++i) {
        printf("%d ", answer[i]);
    }

    return 0;
}