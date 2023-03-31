#include <cstdio>

#define RIGHT 0
#define LEFT 1
#define UP 2
#define DOWN 3
#define WHITE 0
#define RED 1
#define BLUE 2
#define OUTOFBOUNDS -1

using namespace std;

constexpr int MAX_ANSWER = 1000;
constexpr int MAX_N = 12;
constexpr int MAX_K = 10;
constexpr int dict[] = {0, 2, 1, 4, 3};
constexpr int dx[] = {0, 0, 0, -1, 1};
constexpr int dy[] = {0, 1, -1, 0, 0};

struct Piece {
    int x;
    int y;
    int d;
} pieces[1 + MAX_K];

int N, K;
int map[1 + MAX_N + 1][1 + MAX_N + 1];
int stack[1 + MAX_N][1 + MAX_N][1 + MAX_K];

int main() {
    /*
     * Input.
     */
    scanf("%d%d", &N, &K);

    for (int i = 0, endi = N + 1; N >= i; ++i) {
        map[0][i] = map[i][0] = map[endi][i] = map[i][endi] = -1;
    }

    for (int i = 1; N >= i; ++i) {
        for (int j = 1; N >= j; ++j) {
            scanf("%d", &map[i][j]);
        }
    }

    for (int i = 1, x, y, d; K >= i; ++i) {
        scanf("%d%d%d", &x, &y, &d);

        pieces[i].x = x;
        pieces[i].y = y;
        pieces[i].d = d;

        stack[x][y][++stack[x][y][0]] = i;
    }

    /*
     * Compute and Output.
     */
    for (int answer = 1, x, y, d, c, nx, ny; MAX_ANSWER >= answer; ++answer) {
        for (int k = 1; K >= k; ++k) {
            x = pieces[k].x;
            y = pieces[k].y;
            d = pieces[k].d;

            // Find color.
            nx = x + dx[d];
            ny = y + dy[d];
            c = map[nx][ny];

            if (BLUE == c || OUTOFBOUNDS == c) {
                d = dict[d];

                nx = x + dx[d];
                ny = y + dy[d];
                c = map[nx][ny];
                pieces[k].d = d;
            }

            // Move piece.
            if (WHITE == c) {
                int pos;

                for (pos = 1; stack[x][y][0] >= pos && k != stack[x][y][pos]; ++pos) {}

                for (int i = pos; stack[x][y][0] >= i; ++i) {
                    stack[nx][ny][++stack[nx][ny][0]] = stack[x][y][i];
                    pieces[stack[x][y][i]].x = nx;
                    pieces[stack[x][y][i]].y = ny;
                }

                stack[x][y][0] = pos - 1;
            }
            else if (RED == c) {
                int pos;

                for (pos = stack[x][y][0]; pos; --pos) {
                    stack[nx][ny][++stack[nx][ny][0]] = stack[x][y][pos];
                    pieces[stack[x][y][pos]].x = nx;
                    pieces[stack[x][y][pos]].y = ny;

                    if (k == stack[x][y][pos]) {
                        break;
                    }
                }

                stack[x][y][0] = pos - 1;
            }

            // Check exit condition.
            if (4 <= stack[nx][ny][0]) {
                printf("%d", answer);

                return 0;
            }
        }
    }

    printf("-1");

    return 0;
}