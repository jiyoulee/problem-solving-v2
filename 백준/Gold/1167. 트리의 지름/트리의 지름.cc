#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

constexpr int MAX_V = 100000;

int V;
vector<pair<int,int>> graph[1 + MAX_V + 5];
int g_node = 1, g_dist;

void dfs(int node, int parent, int dist);

int main() {
    /*
     * Input.
     */
    scanf("%d", &V);

    for (int i = 0, n1, n2, d; V > i; ++i) {
        scanf("%d", &n1);

        for (scanf("%d", &n2); -1 != n2; scanf("%d", &n2)) {
            scanf("%d", &d);

            graph[n1].emplace_back(n2, d);
        }
    }

    /*
     * Compute.
     */
    dfs(g_node, g_node, 0);
    dfs(g_node, g_node, 0);

    /*
     * Output.
     */
    printf("%d", g_dist);

    return 0;
}

void dfs(int node, int parent, int dist) {
    for (auto& e : graph[node]) {
        if (parent != e.first) {
            dfs(e.first, node, dist + e.second);
        }
    }

    if (g_dist < dist) {
        g_node = node;
        g_dist = dist;
    }

    return;
}