#include <cstdio>

using namespace std;

constexpr int MAX_STR = 100;

int answer[26];
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
        ++answer[str[i] - 'a'];
    }
    
    /*
     * Output.
     */
    for (int i = 0; 26 > i; ++i) {
        printf("%d ", answer[i]);
    }
    
    return 0;
}