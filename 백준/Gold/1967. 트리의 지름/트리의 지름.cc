#include <cstdio>
#include <vector>

using namespace std;

constexpr int MAX_N = 10000;

int answer;
int N;
vector<pair<int,int>> tree[1 + MAX_N];
int node = 1;

void dfs(int cur_node, int prev_node, int cost);

int main() {
    /*
     * Input.
     */
    scanf("%d\n", &N);

    for (int i = 1, U, V, W; N > i; ++i) {
        scanf("%d%d%d", &U, &V, &W);

        tree[U].emplace_back(V, W);
        tree[V].emplace_back(U, W);
    }

    /*
     * Compute.
     */
    dfs(1, 0, 0);

    answer = 0;

    dfs(node, 0, 0);

    /*
     * Output.
     */
    printf("%d", answer);

    return 0;
}

void dfs(int cur_node, int prev_node, int cost) {
    for (auto& e : tree[cur_node]) {
        if (prev_node != e.first) {
            dfs(e.first, cur_node, cost + e.second);
        }
    }

    if (cost > answer) {
        answer = cost;
        node = cur_node;
    }

    return;
}