#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> sets(n);
        vector<int> freq(m + 1, 0);

        for (int i = 0; i < n; i++)
        {
            int li;
            cin >> li;
            sets[i].resize(li);
            for (int j = 0; j < li; j++)
            {
                cin >> sets[i][j];
                freq[sets[i][j]]++;
            }
        }

        // Check full coverage
        bool full = true;
        for (int i = 1; i <= m; i++)
        {
            if (freq[i] == 0)
            {
                full = false;
                break;
            }
        }
        if (!full)
        {
            cout << "NO\n";
            continue;
        }

        // Count how many sets are redundant
        int redundant = 0;
        for (int i = 0; i < n; i++)
        {
            bool essential = false;
            for (int x : sets[i])
            {
                if (freq[x] == 1)
                { // this set provides a unique element
                    essential = true;
                    break;
                }
            }
            if (!essential)
                redundant++;
        }

        cout << (redundant >= 2 ? "YES\n" : "NO\n");
    }
    return 0;
}
