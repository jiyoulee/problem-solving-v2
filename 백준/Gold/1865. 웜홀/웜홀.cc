#include <cstdio>
#include <tuple>
#include <vector>
#include <cstring>

using namespace std;

constexpr int INF = 1 << 30;
constexpr int MAX_N = 500;

int T, N, M, W;
vector<tuple<int,int,int>> graph;
int dist[1 + MAX_N + 10];
bool is_valid;

int main() {
    for (scanf("%d", &T); T--; ) {
        /*
         * Input.
         */
        scanf("%d%d%d", &N, &M, &W);

        for (int i = 0, S, E, C; M > i; ++i) {
            scanf("%d%d%d", &S, &E, &C);

            graph.emplace_back(S, E, C);
            graph.emplace_back(E, S, C);
        }

        for (int i = 0, S, E, C; W > i; ++i) {
            scanf("%d%d%d", &S, &E, &C);

            graph.emplace_back(S, E, -C);
        }

        /*
         * Compute and Output.
         */
        is_valid = true;

        for (int k = 0; N >= k && is_valid; ++k) {
            for (int i = 0, endi = graph.size(), s, e, c; endi > i; ++i) {
                s = get<0>(graph[i]);
                e = get<1>(graph[i]);
                c = get<2>(graph[i]);

                if (INF != dist[s] && dist[e] > dist[s] + c) {
                    if (N == k) {
                        printf("YES\n");

                        is_valid = false;
                        break;
                    }

                    dist[e] = dist[s] + c;
                }
            }
        }

        if (is_valid) {
            printf("NO\n");
        }

        /*
         * Reset.
         */
        graph.clear();
        memset(dist, 0, sizeof(dist));
    }

    return 0;
}