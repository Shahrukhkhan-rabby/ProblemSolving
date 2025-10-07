#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> avoidFlood(vector<int> &rains)
    {
        int n = rains.size();
        vector<int> ans(n, 1);
        unordered_map<int, int> full; // lake -> last day it was filled
        set<int> dry_days;            // indices of days where rains[i] == 0

        for (int i = 0; i < n; ++i)
        {
            int lake = rains[i];

            if (lake == 0)
            {
                // store this dry day index for possible future use
                dry_days.insert(i);
            }
            else
            {
                ans[i] = -1; // raining day, cannot choose which lake to dry

                if (full.count(lake))
                {
                    // lake already full, must find a dry day after last fill
                    auto it = dry_days.upper_bound(full[lake]);
                    if (it == dry_days.end())
                    {
                        // no dry day available → flood unavoidable
                        return {};
                    }
                    ans[*it] = lake;    // assign this dry day to dry this lake
                    dry_days.erase(it); // remove that dry day from available list
                }

                full[lake] = i; // update last filled day for this lake
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> rains = {1, 2, 0, 0, 2, 1};
    vector<int> result = sol.avoidFlood(rains);

    if (result.empty())
    {
        cout << "[]" << endl;
    }
    else
    {
        cout << "[";
        for (int i = 0; i < result.size(); ++i)
        {
            cout << result[i];
            if (i != result.size() - 1)
                cout << ",";
        }
        cout << "]" << endl;
    }
    return 0;
}
