#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

constexpr int MAX_N = 50;

int answer;
int N;
int A[MAX_N + 10];
int B[MAX_N + 10];

int main() {
    /*
     * Input.
     */
    scanf("%d", &N);
    
    for (int i = 0; N > i; ++i) {
        scanf("%d", &A[i]);
    }
    
    for (int i = 0; N > i; ++i) {
        scanf("%d", &B[i]);
    }
    
    /*
     * Compute.
     */
    sort(A, A + N);
    sort(B, B + N, greater<int>());
    
    for (int i = 0; N > i; ++i) {
        answer += A[i] * B[i];
    }
    
    /*
     * Output.
     */
    printf("%d", answer);
    
    return 0;
}