#include <cstdio>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

constexpr int MAX_ANSWER = 100;
constexpr int MAX_N = 100;
constexpr int MAX_M = 100;
constexpr int MAX_P = 100;

int answer;
int R, C, K;
int A[1 + MAX_N + 1][1 + MAX_M + 1];
int N = 3, M = 3;
int p, tmp;
int cnt[1 + MAX_P];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_pq;

int main() {
    /*
     * Input.
     */
    scanf("%d%d%d", &R, &C, &K);

    for (int i = 1; 3 >= i; ++i) {
        for (int j = 1; 3 >= j; ++j) {
            scanf("%d", &A[i][j]);
        }
    }

    /*
     * Compute.
     */
    for (; MAX_ANSWER >= answer && K != A[R][C]; ++answer) {
        if (N >= M) {
            tmp = M;

            for (int i = 1; N >= i; ++i) {
                for (int j = 1; tmp >= j; ++j) {
                    if (A[i][j]) {
                        ++cnt[A[i][j]];
                    }
                }

                min_pq = priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>();

                for (p = 1; MAX_P >= p; ++p) {
                    if (cnt[p]) {
                        min_pq.emplace(cnt[p], p);
                        cnt[p] = 0;
                    }
                }

                for (p = 1; MAX_P >= p && !min_pq.empty(); min_pq.pop())  {
                    A[i][p++] = min_pq.top().second;
                    A[i][p++] = min_pq.top().first;
                }

                if (p - 1 > M) {
                    M = p - 1;
                }
                for (; tmp >= p; ++p) {
                    A[i][p] = 0;
                }
            }
        }
        else {
            tmp = N;

            for (int j = 1; M >= j; ++j) {
                for (int i = 1; tmp >= i; ++i) {
                    if (A[i][j]) {
                        ++cnt[A[i][j]];
                    }
                }

                min_pq = priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>();

                for (p = 1; MAX_P >= p; ++p) {
                    if (cnt[p]) {
                        min_pq.emplace(cnt[p], p);
                        cnt[p] = 0;
                    }
                }

                for (p = 1; MAX_P >= p && !min_pq.empty(); min_pq.pop())  {
                    A[p++][j] = min_pq.top().second;
                    A[p++][j] = min_pq.top().first;
                }

                if (p - 1 > N) {
                    N = p - 1;
                }
                for (; tmp >= p; ++p) {
                    A[p][j] = 0;
                }
            }
        }
    }

    /*
     * Output.
     */
    printf("%d", (MAX_ANSWER >= answer) ? answer : -1);

    return 0;
}