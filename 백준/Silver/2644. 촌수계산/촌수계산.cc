#include <cstdio>
#include <vector>
#include <queue>

constexpr int MAX_N = 100;

using namespace std;

int answer = -1;
int N, P1, P2, M;
vector<int> graph[1 + MAX_N];
queue<pair<int,int>> q;
bool visited[1 + MAX_N];

int main() {
    /*
     * Input.
     */
    scanf("%d%d%d%d", &N, &P1, &P2, &M);

    for (int x, y; M--; ) {
        scanf("%d%d", &x, &y);

        graph[x].emplace_back(y);
        graph[y].emplace_back(x);
    }

    /*
     * Compute and Output.
     */
    visited[P1] = true;
    q.emplace(P1, 0);

    for (int cur_p, ts; !q.empty(); ) {
        cur_p = q.front().first;
        ts = q.front().second;

        if (P2 == cur_p) {
            printf("%d", ts);

            return 0;
        }

        q.pop();

        for (auto& new_p : graph[cur_p]) {
            if (!visited[new_p]) {
                visited[new_p] = true;
                q.emplace(new_p, ts + 1);
            }
        }
    }

    printf("-1");

    return 0;
}