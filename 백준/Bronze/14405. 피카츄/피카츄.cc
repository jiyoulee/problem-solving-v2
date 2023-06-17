#include <cstdio>
#include <cstring>

using namespace std;

constexpr int MAX_S = 5000;

int answer;
char S[MAX_S + 10];

int main() {
    /*
     * Input.
     */
    scanf("%s", S);
    
    /*
     * Compute.
     */
    while (S[answer]) {
        if (('p' == S[answer] && 'i' == S[answer + 1]) || ('k' == S[answer] && 'a' == S[answer + 1])) {
            answer += 2;
        }
        else if ('c' == S[answer] && 'h' == S[answer + 1] && 'u' == S[answer + 2]) {
            answer += 3;
        }
        else {
            break;
        }
    }
    
    /*
     * Output.
     */
    printf("%s", (strlen(S) == answer) ? "YES" : "NO");
    
    return 0;
}