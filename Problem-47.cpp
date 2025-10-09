#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minTime(vector<int> &skill, vector<int> &mana)
    {
        int n = (int)skill.size();
        int m = (int)mana.size();
        // prefix sums A[i] for current potion: A[0]=0, A[k]=sum_{t=0..k-1} p[t]
        vector<long long> A_curr(n + 1, 0), A_next(n + 1, 0);

        // compute prefix for potion 0
        for (int i = 0; i < n; ++i)
        {
            A_curr[i + 1] = A_curr[i] + 1LL * skill[i] * mana[0];
        }

        if (m == 1)
            return A_curr[n]; // only one potion

        long long S = 0; // start time of current potion at machine 0 (S_0 = 0)

        // for each adjacent pair j and j+1 compute delta and advance S
        for (int j = 0; j < m - 1; ++j)
        {
            // build prefix for potion j+1
            for (int i = 0; i < n; ++i)
            {
                A_next[i + 1] = A_next[i] + 1LL * skill[i] * mana[j + 1];
            }

            long long delta = LLONG_MIN;
            for (int i = 0; i < n; ++i)
            {
                // requirement from machine i:
                long long val = A_curr[i + 1] - A_next[i];
                if (val > delta)
                    delta = val;
            }
            S += delta; // S_{j+1} = S_j + delta
            // move next -> curr, reset A_next[0..n] to 0 for next iteration
            swap(A_curr, A_next);
            fill(A_next.begin(), A_next.end(), 0);
        }

        // after loop, A_curr holds prefix sums for last potion (m-1)
        long long makespan = S + A_curr[n];
        return makespan;
    }
};

#ifdef LOCAL_TEST
int main()
{
    Solution sol;
    vector<int> skill1 = {1, 5, 2, 4};
    vector<int> mana1 = {5, 1, 4, 2};
    cout << sol.minTime(skill1, mana1) << '\n'; // 110

    vector<int> skill2 = {1, 1, 1};
    vector<int> mana2 = {1, 1, 1};
    cout << sol.minTime(skill2, mana2) << '\n'; // 5

    vector<int> skill3 = {1, 2, 3, 4};
    vector<int> mana3 = {1, 2};
    cout << sol.minTime(skill3, mana3) << '\n'; // 21
    return 0;
}
#endif
