#include <cstdio>
#include <algorithm>

using namespace std;

long long int A, B;
long long int a, b;

int main() {
    /*
     * Input.
     */
    scanf("%lld%lld", &A, &B);
    
    /*
     * Compute.
     */
    if (A > B) {
        swap(A, B);
    }

    if (0 <= A) {
        a = (abs(A) * (abs(A) - 1)) >> 1;
        b = (abs(B) * (abs(B) + 1)) >> 1;
    }
    else if (0 >= B) {
        a = (abs(A) * (abs(A) + 1)) >> 1;
        b = (abs(B) * (abs(B) - 1)) >> 1;
    }
    else {
        a = (abs(A) * (abs(A) + 1)) >> 1;
        b = (abs(B) * (abs(B) + 1)) >> 1;
    }
    
    
    /*
     * Output.
     */
    printf("%lld", b - a);
    
    return 0;
}