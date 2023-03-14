import sys

input = sys.stdin.readline

# 점의 개수를 입력받는다.
N = int(input())

# 점의 좌표를 입력받는다.
C = [list(map(int, input().split())) for _ in range(N)]

# 정답(i.e., 직각삼각형의 개수)를 초기화한다.
answer = 0

# (모든 경우의 수를 탐색하면서) 직각삼각형의 성질을 활용하여 정답을 갱신한다.
for t1 in range(N - 2):
    for t2 in range(t1 + 1, N - 1):
        for t3 in range(t2 + 1, N):
            # [옵션1] 피타고리스 정리
            h1 = (C[t1][0] - C[t2][0]) ** 2 + (C[t1][1] - C[t2][1]) ** 2
            h2 = (C[t2][0] - C[t3][0]) ** 2 + (C[t2][1] - C[t3][1]) ** 2
            h3 = (C[t3][0] - C[t1][0]) ** 2 + (C[t3][1] - C[t1][1]) ** 2
            
            # if h1 + h2 + h3 == 2 * max(h1, h2, h3):
            #    answer += 1
            if h1 == h2 + h3 or h2 == h1 + h3 or h3 == h1 + h2:
               answer += 1

            # [옵션2] 백터의 내적
            # ip1 = (C[t2][0] - C[t1][0]) * (C[t3][0] - C[t1][0]) + (C[t2][1] - C[t1][1]) * (C[t3][1] - C[t1][1])
            # ip2 = (C[t1][0] - C[t2][0]) * (C[t3][0] - C[t2][0]) + (C[t1][1] - C[t2][1]) * (C[t3][1] - C[t2][1])
            # ip3 = (C[t1][0] - C[t3][0]) * (C[t2][0] - C[t3][0]) + (C[t1][1] - C[t3][1]) * (C[t1][1] - C[t3][1])

            # if not ip1 or not ip2 or not ip3:
            #    answer += 1

# 정답을 출력한다.
print(answer)
