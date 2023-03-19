#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

constexpr int MAX_N = 300000;
constexpr int MAX_K = 300000;

long long int answer;
int N, K;
pair<int,int> jewels[MAX_N];
multiset<int> bags;

bool cmp(pair<int,int> p1, pair<int,int> p2);

int main() {
    /*
     * Input
     */
    scanf("%d%d", &N, &K);

    for (int i = 0; N > i; ++i) {
        scanf("%d%d", &jewels[i].first, &jewels[i].second);
    }

    for (int i = 0, tmp; K > i; ++i) {
        scanf("%d", &tmp);

        bags.emplace(tmp);
    }

    /*
     * Compute.
     */
    sort(jewels, jewels + N, cmp);

    for (int i = 0; N > i && bags.size(); ++i) {
        auto it = bags.lower_bound(jewels[i].first);

        if (bags.end() != it) {
            answer += jewels[i].second;

            bags.erase(it);
        }
    }

    /*
     * Output.
     */
    printf("%lld", answer);

    return 0;
}

bool cmp(pair<int,int> p1, pair<int,int> p2) {
    if (p2.second == p1.second) {
        return p1.first < p2.first;
    }

    return p1.second > p2.second;
}