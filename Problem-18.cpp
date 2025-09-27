#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills, int strength)
    {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int n = tasks.size(), m = workers.size();
        int lo = 0, hi = min(n, m), ans = 0;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (canAssign(mid, tasks, workers, pills, strength))
            {
                ans = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        return ans;
    }

private:
    // Check if we can assign k tasks (the k smallest tasks) using k strongest workers
    bool canAssign(int k, const vector<int> &tasks, const vector<int> &workers, int pills, int strength)
    {
        if (k == 0)
            return true;
        int m = workers.size();
        // Insert the k strongest workers into a multiset (sorted)
        multiset<long long> ws;
        for (int i = m - k; i < m; ++i)
            ws.insert((long long)workers[i]);

        // Iterate the k smallest tasks from largest -> smallest
        for (int i = k - 1; i >= 0; --i)
        {
            long long need = tasks[i];
            auto it_strong = prev(ws.end()); // strongest available worker
            if (*it_strong >= need)
            {
                ws.erase(it_strong); // assign without pill
            }
            else
            {
                if (pills == 0)
                    return false;
                // find the weakest worker that can reach 'need' after taking a pill
                long long mustBe = need - (long long)strength;
                auto it = ws.lower_bound(mustBe);
                if (it == ws.end())
                    return false; // no worker can reach even with pill
                ws.erase(it);
                --pills;
            }
        }
        return true;
    }
};
