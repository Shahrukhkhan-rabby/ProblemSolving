import sys
import bisect

input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    s = input().strip()
    initial_black = list(map(int, input().split()))

    black = set(initial_black)  # track black cells
    pos = 1

    for c in s:
        if c == "A":
            pos += 1
        else:  # B command
            while pos + 1 in black:
                pos += 1
            pos += 1
        black.add(pos)

    black = sorted(black)
    print(len(black))
    print(" ".join(map(str, black)))
