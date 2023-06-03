#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int answer;
string N;
int B;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    /*
     * Input.
     */
    cin >> N >> B;
    
    /*
     * Compute.
     */
    for (int i = 0; N[i]; ++i) {
        answer *= B;
        answer += N[i] - (isupper(N[i]) ? ('A' - 10) : '0');
    }
    
    /*
     * Output.
     */
    cout << answer;
    
    return 0;
}