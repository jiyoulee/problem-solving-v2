#include <cstdio>

#define U 1
#define D 2
#define R 3
#define L 4

using namespace std;

constexpr int MAX_N = 100;
constexpr int MAX_M = 100;

struct Shark {
    int s;
    int d;
    int z;
};

int answer;
int N, M, K;
int cpos, npos;
Shark sharks[2][1 + MAX_N][1 + MAX_M];

int main() {
    /*
     * Preset.
     */
    cpos = 0;
    npos = 1;

    /*
     * Input.
     */
    scanf("%d%d%d", &N, &M, &K);

    for (int r, c, s, d, z; K--; ) {
        scanf("%d%d%d%d%d", &r, &c, &s, &d, &z);

        sharks[cpos][r][c].s = s;
        sharks[cpos][r][c].d = d;
        sharks[cpos][r][c].z = z;
    }

    /*
     * Compute.
     */
    for (int fisherman = 1; M >= fisherman; ++fisherman, cpos ^= 1, npos ^= 1) {
        /*
         * Catch shark.
         */
        for (int i = 1; N >= i; ++i) {
            if (sharks[cpos][i][fisherman].d) {
                answer += sharks[cpos][i][fisherman].z;
                sharks[cpos][i][fisherman].d = 0;
                break;
            }
        }

        /*
         * Move shark.
         */
        for (int i = 1; N >= i; ++i) {
            for (int j = 1; M >= j; ++j) {
                if (sharks[cpos][i][j].d) {
                    int ni = i;
                    int nj = j;
                    int ns = sharks[cpos][i][j].s;
                    int nd = sharks[cpos][i][j].d;
                    int nz = sharks[cpos][i][j].z;
                    int tmp = sharks[cpos][i][j].s;
                    int q, diff;

                    sharks[cpos][i][j].d = 0;

                    /*
                     * Phase 1.
                     */
                    switch(nd) {
                        case U:
                            diff = ni - 1;

                            ni = (diff > tmp) ? ni - tmp : 1;
                            tmp -= diff;

                            if (0 < tmp) {
                                if ((tmp / (N - 1)) & 1) {
                                    ni = N;
                                    nd = D;
                                }

                                tmp %= N - 1;

                                if (tmp) {
                                    if (U == nd) {
                                        ni += tmp;
                                        nd = D;
                                    }
                                    else {
                                        ni -= tmp;
                                        nd = U;
                                    }
                                }
                            }
                            
                            break;
                        case D:
                            diff = N - ni;

                            ni = (diff > tmp) ? ni + tmp : N;
                            tmp -= diff;


                            if (0 < tmp) {
                                if ((tmp / (N - 1)) & 1) {
                                    ni = 1;
                                    nd = U;
                                }

                                tmp %= N - 1;

                                if (tmp) {
                                    if (D == nd) {
                                        ni -= tmp;
                                        nd = U;
                                    }
                                    else {
                                        ni += tmp;
                                        nd = D;
                                    }
                                }
                            }

                            break;
                        case R:
                            diff = M - nj;

                            nj = (diff > tmp) ? nj + tmp : M;
                            tmp -= diff;

                            if (0 < tmp) {
                                if ((tmp / (M - 1)) & 1) {
                                    nj = 1;
                                    nd = L;
                                }

                                tmp %= M - 1;

                                if (tmp) {
                                    if (R == nd) {
                                        nj -= tmp;
                                        nd = L;
                                    }
                                    else {
                                        nj += tmp;
                                        nd = R;
                                    }
                                }
                            }

                            break;
                        case L:
                            diff = nj - 1;

                            nj = (diff > tmp) ? nj - tmp : 1;
                            tmp -= diff;

                            if (0 < tmp) {
                                if ((tmp / (M - 1)) & 1) {
                                    nj = M;
                                    nd = R;
                                }

                                tmp %= M - 1;

                                if (tmp) {
                                    if (L == nd) {
                                        nj += tmp;
                                        nd = R;
                                    }
                                    else {
                                        nj -= tmp;
                                        nd = L;
                                    }
                                }
                            }

                            break;
                        default:
                            // do nothing
                            break;
                    }

                    /*
                     * Phase 2.
                     */
                    if (sharks[npos][ni][nj].d && sharks[npos][ni][nj].z > nz) {
                        continue;
                    }

                    sharks[npos][ni][nj].s = ns;
                    sharks[npos][ni][nj].d = nd;
                    sharks[npos][ni][nj].z = nz;
                }
            }
        }
    }

    /*
     * Output.
     */
    printf("%d", answer);

    return 0;
}