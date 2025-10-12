#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 MOD = 1000000007;

int64 modpow(int64 a, int64 e)
{
    int64 r = 1 % MOD;
    a %= MOD;
    while (e)
    {
        if (e & 1)
            r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}

// small n (<=50) combinatorics table, mod MOD
vector<vector<int64>> build_nCr(int N)
{
    vector<vector<int64>> C(N + 1, vector<int64>(N + 1, 0));
    for (int i = 0; i <= N; ++i)
    {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j)
        {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }
    return C;
}

class Solution
{
public:
    // Method name matches what your harness expects:
    int magicalSum(int m, int k, vector<int> &nums)
    {
        int n = (int)nums.size();
        // Edge quick checks
        if (k > n)
            return 0;
        // Precompute powers a^q for q up to m for each a (mod MOD)
        vector<vector<int64>> powA(n, vector<int64>(m + 1, 1));
        for (int i = 0; i < n; ++i)
        {
            for (int q = 1; q <= m; ++q)
                powA[i][q] = (powA[i][q - 1] * (nums[i] % MOD)) % MOD;
        }

        // Precompute binomial coefficients up to m for use in (S + a)^p expansion
        vector<vector<int64>> binom(m + 1, vector<int64>(m + 1, 0));
        for (int i = 0; i <= m; ++i)
        {
            binom[i][0] = binom[i][i] = 1;
            for (int j = 1; j < i; ++j)
                binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % MOD;
        }

        // dp[t][p] = sum over subsets T of size t of (sum_{i in T} nums[i])^p  (mod MOD)
        // We only need p up to m, t up to min(n,k) but compute up to n for safety
        vector<vector<int64>> dp(n + 1, vector<int64>(m + 1, 0));
        dp[0][0] = 1; // empty subset has sum 0, (0)^0 treated as 1 for combinatorial expansion

        // Process each number, update dp descending on t
        for (int idx = 0; idx < n; ++idx)
        {
            int64 a0 = nums[idx] % MOD;
            // Update dp in reverse t to avoid reuse within same iteration
            for (int t = idx; t >= 0; --t)
            {
                // dp[t] contributes to dp[t+1] after including current element
                // newP = 0..m: (S + a)^newP = sum_{q=0..newP} C(newP,q) * S^{newP-q} * a^q
                for (int newP = m; newP >= 0; --newP)
                {
                    int64 add = 0;
                    for (int q = 0; q <= newP; ++q)
                    {
                        // term = C(newP, q) * dp[t][newP-q] * a^q
                        int64 term = dp[t][newP - q];
                        if (term == 0)
                            continue;
                        int64 c = binom[newP][q];
                        int64 apow = powA[idx][q];
                        term = ((term * c) % MOD * apow) % MOD;
                        add += term;
                        if (add >= (1LL << 62))
                            add %= MOD; // safety
                    }
                    if (add)
                    {
                        dp[t + 1][newP] += (add % MOD);
                        if (dp[t + 1][newP] >= MOD)
                            dp[t + 1][newP] -= MOD;
                    }
                }
            }
        }

        // Precompute small nCr table for up to n (for C(n-t, k-t) factor)
        auto nCr = build_nCr(n);

        int64 ans = 0;
        // sum over t = 1..k of (-1)^{k-t} * C(n - t, k - t) * dp[t][m]
        for (int t = 1; t <= k; ++t)
        {
            if (t > n)
                break;
            int64 waysChoose = nCr[n - t][k - t];  // C(n-t, k-t) mod MOD (0 if invalid)
            int64 subsetPowerSum = dp[t][m] % MOD; // sum_{|T|=t} (sum_T)^m
            int64 term = (waysChoose * subsetPowerSum) % MOD;
            if ((k - t) % 2 == 1)
            { // sign negative
                ans -= term;
            }
            else
            {
                ans += term;
            }
            ans %= MOD;
        }
        if (ans < 0)
            ans += MOD;
        return (int)ans;
    }
};

// Example quick test (uncomment to run in a local env)
/*
int main() {
    Solution s;
    vector<int> a1 = {1,10,100,10000,1000000};
    cout << s.magicalSum(5,5,a1) << endl; // expected 991600007
    vector<int> a2 = {5,4,3,2,1};
    cout << s.magicalSum(2,2,a2) << endl; // expected 170
    vector<int> a3 = {28};
    cout << s.magicalSum(1,1,a3) << endl; // expected 28
}
*/
