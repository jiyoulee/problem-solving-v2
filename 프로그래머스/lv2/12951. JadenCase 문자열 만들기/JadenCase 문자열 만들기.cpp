#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    
    answer += toupper(s[0]);
    
    for (int i = 1, endi = s.size(); endi > i; ++i) {
        answer += (' ' == s[i - 1]) ? toupper(s[i]) : tolower(s[i]);
    }
    
    return answer;
}