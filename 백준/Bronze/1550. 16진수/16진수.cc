#include <cstdio>
#include <string>

using namespace std;

constexpr int MAX_STR = 6;

int answer;
char str[MAX_STR + 1];

int main() {
    /*
     * Input.
     */
    scanf("%s", str);
    
    /*
     * Compute.
     */
    for (int i = 0; str[i]; ++i) {
        answer <<= 4;
        answer += isupper(str[i]) ? (str[i] - 'A' + 10) : (str[i] - '0');
    }
    
    /*
     * Output.
     */
    printf("%d", answer);
    
    return 0;
}