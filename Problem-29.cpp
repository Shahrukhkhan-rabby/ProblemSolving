#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();

        // Step 1: Place each number in its correct position if possible
        for (int i = 0; i < n; i++)
        {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Step 2: Find the first missing positive
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i + 1)
            {
                return i + 1;
            }
        }

        // Step 3: If all are correct, return n+1
        return n + 1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1, 2, 0};
    vector<int> nums2 = {3, 4, -1, 1};
    vector<int> nums3 = {7, 8, 9, 11, 12};

    cout << sol.firstMissingPositive(nums1) << endl; // 3
    cout << sol.firstMissingPositive(nums2) << endl; // 2
    cout << sol.firstMissingPositive(nums3) << endl; // 1
    return 0;
}
