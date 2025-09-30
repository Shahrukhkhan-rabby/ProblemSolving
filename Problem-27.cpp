#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int triangularSum(vector<int> &nums)
    {
        int n = nums.size();
        // Keep reducing until one element remains
        for (int len = n; len > 1; len--)
        {
            for (int i = 0; i < len - 1; i++)
            {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
        }
        return nums[0]; // final single element
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 4, 5};
    cout << sol.triangularSum(nums1) << endl; // Output: 8

    vector<int> nums2 = {5};
    cout << sol.triangularSum(nums2) << endl; // Output: 5
}
