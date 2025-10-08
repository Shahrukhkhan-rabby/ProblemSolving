#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        sort(potions.begin(), potions.end());
        int m = potions.size();
        vector<int> result;
        result.reserve(spells.size());

        for (int s : spells)
        {
            long long minPotion = (success + s - 1) / s; // ceil(success / s)
            auto it = lower_bound(potions.begin(), potions.end(), minPotion);
            result.push_back((int)(potions.end() - it));
        }

        return result;
    }
};

int main()
{
    vector<int> spells = {5, 1, 3};
    vector<int> potions = {1, 2, 3, 4, 5};
    long long success = 7;

    vector<int> ret = Solution().successfulPairs(spells, potions, success);
    for (int x : ret)
        cout << x << " ";
    cout << "\n";
    return 0;
}
