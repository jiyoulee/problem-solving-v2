#include <cstdio>
#include "user.h"

using namespace std;

constexpr int MAX_M = 100000;

int Q, mN, mM;
int mA[MAX_M];
int cmd;
int m_src, m_dst, p_num, b_num;

int main() {
    freopen("test.txt", "r", stdin);

    for (scanf("%d", &Q); Q--; ) {
        scanf("%d", &cmd);

        switch (cmd) {
        case 100:
            scanf("%d%d", &mN, &mM);
            for (int i = 0; mM > i; ++i) {
                scanf("%d", &mA[i]);
            }
            init(mN, mM, mA);
            break;
        case 200:
            scanf("%d%d", &m_src, &m_dst);
            printf("%d\n", moveAll(m_src, m_dst));
            break;
        case 300:
            scanf("%d%d", &m_src, &m_dst);
            printf("%d\n", moveFront(m_src, m_dst));
            break;
        case 400:
            scanf("%d%d", &m_src, &m_dst);
            printf("%d\n", moveHalf(m_src, m_dst));
            break;
        case 500:
            scanf("%d", &p_num);
            printf("%d\n", getPresent(p_num));
            break;
        case 600:
            scanf("%d", &b_num);
            printf("%d\n", getBelt(b_num));
            break;
        default:
            // do nothing
            break;
        }
    }

    return 0;
}