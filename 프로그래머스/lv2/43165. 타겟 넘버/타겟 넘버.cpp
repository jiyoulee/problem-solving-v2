#include <string>
#include <vector>
#include <queue>

using namespace std;

int dfs(int depth, int sum, vector<int>& numbers, int& target) {
    int ret = 0;
    
    if (numbers.size() == depth) {
        if (target == sum) {
            return ret = 1;
        }
        
        return ret = 0;
    }
    
    ret += dfs(depth + 1, sum + numbers[depth], numbers, target);
    ret += dfs(depth + 1, sum - numbers[depth], numbers, target);
    
    return ret;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    answer = dfs(0, 0, numbers, target);
    
    return answer;
}