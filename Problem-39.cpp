#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.empty() || t.empty())
            return "";

        unordered_map<char, int> need, window;
        for (char c : t)
            need[c]++;

        int have = 0, needCount = need.size();
        int left = 0, minLen = INT_MAX, start = 0;

        for (int right = 0; right < s.size(); right++)
        {
            char c = s[right];
            window[c]++;

            if (need.count(c) && window[c] == need[c])
            {
                have++;
            }

            // Try to shrink from left
            while (have == needCount)
            {
                if ((right - left + 1) < minLen)
                {
                    minLen = right - left + 1;
                    start = left;
                }

                char d = s[left];
                window[d]--;
                if (need.count(d) && window[d] < need[d])
                {
                    have--;
                }
                left++;
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};
