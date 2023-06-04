#include <cstdio>
#include <cmath>

using namespace std;

double D, H, W;
double x;

int main() {
    /*
     * Input.
     */
    scanf("%lf%lf%lf", &D, &H, &W);
    
    /*
     * Compute.
     */
    x = sqrt(pow(D, 2) / (pow(H, 2) + pow(W, 2)));
    
    /*
     * Output.
     */
    printf("%.0lf %.0lf", floor(H * x), floor(W * x));
    
    return 0;
}