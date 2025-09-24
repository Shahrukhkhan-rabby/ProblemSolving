#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    // If all positions are unstable, impossible
    if (count(s.begin(), s.end(), '1') == 0)
    {
        cout << "NO\n";
        return;
    }

    // Initialize permutation
    vector<int> p(n + 1, 0);
    vector<int> stable_pos, unstable_pos;
    vector<int> stable_nums, unstable_nums;

    // Collect stable and unstable numbers and positions
    for (int i = 1; i <= n; ++i)
    {
        if (s[i - 1] == '1')
        {
            stable_nums.push_back(i);
            stable_pos.push_back(i);
        }
        else
        {
            unstable_nums.push_back(i);
            unstable_pos.push_back(i);
        }
    }

    // Sort positions and numbers
    sort(stable_pos.begin(), stable_pos.end());
    sort(stable_nums.begin(), stable_nums.end());
    sort(unstable_pos.begin(), unstable_pos.end());
    sort(unstable_nums.rbegin(), unstable_nums.rend()); // Decreasing order for instability

    // Assign stable numbers to stable positions
    for (size_t i = 0; i < stable_pos.size(); ++i)
    {
        p[stable_pos[i]] = stable_nums[i];
    }

    // Assign unstable numbers to unstable positions
    for (size_t i = 0; i < unstable_pos.size(); ++i)
    {
        p[unstable_pos[i]] = unstable_nums[i];
    }

    // Output the permutation
    cout << "YES\n";
    for (int i = 1; i <= n; ++i)
    {
        cout << p[i] << " ";
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}