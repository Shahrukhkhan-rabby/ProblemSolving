#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        unordered_map<int, int> freq;

        // Step 1: Count frequency of each element
        for (int num : nums)
        {
            freq[num]++;
        }

        // Step 2: Find the maximum frequency
        int maxFreq = 0;
        for (auto &[key, count] : freq)
        {
            if (count > maxFreq)
                maxFreq = count;
        }

        // Step 3: Sum frequencies of elements with maximum frequency
        int total = 0;
        for (auto &[key, count] : freq)
        {
            if (count == maxFreq)
                total += count;
        }

        return total;
    }
};
