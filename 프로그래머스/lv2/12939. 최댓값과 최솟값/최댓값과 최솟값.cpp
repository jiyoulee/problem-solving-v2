#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int tmp = 0, pos = 0, endpos = s.size();
    bool is_valid = true;
    
    for (; endpos > pos && ' ' != s[pos]; ++pos) {
        if ('-' == s[pos]) {
            is_valid = false;
        }
        else {
            tmp *= 10;
            tmp += s[pos] - '0';
        }
    }
    
    if (!is_valid) {
        tmp *= -1;
    }
    
    int minimum = tmp, maximum = tmp;
    
    for (++pos, tmp = 0, is_valid = true; endpos > pos; ++pos, tmp = 0) {
        if ('-' == s[pos]) {
            is_valid = false;
        }
        else {
            for (; endpos > pos && ' ' != s[pos]; ++pos) {
                tmp *= 10;
                tmp += s[pos] - '0';
            }

            if (!is_valid) {
                tmp *= -1;
            }

            if (minimum > tmp) {
                minimum = tmp;
            }
            if (maximum < tmp) {
                maximum = tmp;
            }
            
            is_valid = true;
        }
    }
    
    answer.append(to_string(minimum) + " " + to_string(maximum));
    
    return answer;
}