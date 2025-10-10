#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumEnergy(vector<int> &energy, int k)
    {
        int n = energy.size();
        vector<long long> dp(n);
        long long ans = LLONG_MIN;

        for (int i = n - 1; i >= 0; --i)
        {
            if (i + k < n)
                dp[i] = energy[i] + dp[i + k];
            else
                dp[i] = energy[i];

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> energy1 = {5, 2, -10, -5, 1};
    cout << sol.maximumEnergy(energy1, 3) << endl; // Output: 3

    vector<int> energy2 = {-2, -3, -1};
    cout << sol.maximumEnergy(energy2, 2) << endl; // Output: -1
}
