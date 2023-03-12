#include <cstdio>
#include <cmath>

using namespace std;

int xs, ys, xe, ye, dx, dy;
int tmp;

int gcd(int a, int b);

int main() {
    /*
     * Input.
     */
    scanf("%d%d%d%d%d%d", &xs, &ys, &xe, &ye, &dx, &dy);

    /*
     * Compute.
     */
    tmp = (abs(dx) > abs(dy) ? gcd(abs(dx), abs(dy)) : gcd(abs(dy), abs(dx)));

    if (tmp) {
        dx /= tmp;
        dy /= tmp;
    }

    for (int dist = pow(xs- xe, 2) + pow(ys - ye, 2), dist_new; true; ) {
        xe += dx;
        ye += dy;

        dist_new = pow(xs - xe, 2) + pow(ys - ye, 2);

        /*
         * Output.
         */
        if (dist_new > dist) {
            printf("%d %d", xe - dx, ye - dy);

            return 0;
        }

        dist = dist_new;
    }

    return 0;
}

int gcd(int a, int b) {
    if (0 == b) {
        return a;
    }

    return gcd(b, a % b);
}