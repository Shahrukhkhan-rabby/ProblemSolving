#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int count = 0;

        for (int k = n - 1; k >= 2; k--)
        { // fix the largest side
            int i = 0, j = k - 1;
            while (i < j)
            {
                if (nums[i] + nums[j] > nums[k])
                {
                    count += (j - i); // all pairs between i..j-1 with j are valid
                    j--;
                }
                else
                {
                    i++;
                }
            }
        }
        return count;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {2, 2, 3, 4};
    vector<int> nums2 = {4, 2, 3, 4};

    cout << sol.triangleNumber(nums1) << endl; // 3
    cout << sol.triangleNumber(nums2) << endl; // 4
}
