#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumTotalDamage(vector<int> &power)
    {
        unordered_map<long long, long long> sum; // damage sum per value
        sum.reserve(power.size() * 2);
        for (int x : power)
            sum[x] += (long long)x;

        vector<long long> vals;
        vals.reserve(sum.size());
        for (auto &pr : sum)
            vals.push_back(pr.first);
        sort(vals.begin(), vals.end());

        int n = (int)vals.size();
        if (n == 0)
            return 0;
        vector<long long> dp(n, 0);
        dp[0] = sum[vals[0]];

        for (int i = 1; i < n; ++i)
        {
            long long take = sum[vals[i]];
            // we need the last index j with vals[j] <= vals[i] - 3
            long long need = vals[i] - 3;
            int j = int(upper_bound(vals.begin(), vals.begin() + i, need) - vals.begin()) - 1;
            if (j >= 0)
                take += dp[j];
            dp[i] = max(dp[i - 1], take);
        }
        return dp[n - 1];
    }
};

// Optional main for local testing
int main()
{
    Solution sol;
    vector<int> a = {1, 1, 3, 4};
    cout << sol.maximumTotalDamage(a) << '\n'; // 6

    vector<int> b = {7, 1, 6, 6};
    cout << sol.maximumTotalDamage(b) << '\n'; // 13
    return 0;
}
