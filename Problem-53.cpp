#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findSmallestInteger(vector<int> &nums, int value)
    {
        unordered_map<int, int> count;

        for (int num : nums)
        {
            int r = ((num % value) + value) % value; // handle negative numbers
            count[r]++;
        }

        int mex = 0;
        while (true)
        {
            int r = mex % value;
            if (count[r] > 0)
            {
                count[r]--;
                mex++;
            }
            else
            {
                break;
            }
        }
        return mex;
    }
};
