#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.rbegin(), people.rend());
    
    for (int p = 0, q = people.size() - 1; p <= q; ++p) {
        if (limit >= people[p] + people[q]) {
            --q;
        }
        
        ++answer;
    }
    
    return answer;
}