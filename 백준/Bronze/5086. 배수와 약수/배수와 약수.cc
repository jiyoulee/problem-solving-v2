#include <cstdio>

using namespace std;

int A, B;

int main() {
    while (scanf("%d%d", &A, &B) && A) {
        if (0 == B % A) {
            printf("factor\n");
        }
        else if (0 == A % B) {
            printf("multiple\n");
        }
        else {
            printf("neither\n");
        }
    }
    
    return 0;
}