from collections import Counter


def longest_balanced_subsequence(arr):
    freq = Counter(arr)
    max_freq = max(freq.values())
    ans = 0
    for k in range(1, max_freq + 1):
        cnt = sum(1 for v in freq.values() if v >= k)
        ans = max(ans, cnt * k)
    return ans


t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    print(longest_balanced_subsequence(arr))
