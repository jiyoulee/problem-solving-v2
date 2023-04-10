#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

constexpr int MAX_F = 1000000;

int F, S, G, U, D;
bool visited[1 + MAX_F];

int main() {
    /*
     * Input.
     */
    scanf("%d%d%d%d%d", &F, &S, &G, &U, &D);

    /*
     * Compute and Output.
     */
    queue<pair<int,int>> q;

    visited[S] = true;
    q.emplace(S, 0);

    for (int val, ts; !q.empty(); ) {
        val = q.front().first;
        ts = q.front().second;
        
        // Break.
        if (G == val) {
            printf("%d", ts);

            return 0;
        }

        q.pop();

        // Move.
        if (F >= val + U && !visited[val + U]) {
            visited[val + U] = true;
            q.emplace(val + U, ts + 1);
        }
        if (0 < val - D && !visited[val - D]) {
            visited[val - D] = true;
            q.emplace(val - D, ts + 1);
        }
    }

    printf("use the stairs");

    return 0;
}