#include <cstdio>
#include <cmath>

using namespace std;

double X;

int main() {
    /*
     * Input, Compute, and Output.
     */
    while (scanf("%lf", &X), 0 <= X) {
        printf("Objects weighing %.2lf on Earth will weigh %.2lf on the moon.\n", round(X * 100) / 100, round(X * 16.7) / 100);
    }

    return 0; 
}