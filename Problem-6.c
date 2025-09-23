// Count Elements with Maximum Frequency

int maxFrequencyElements(int *nums, int numsSize)
{
    int freq[101] = {0}; // Since 1 <= nums[i] <= 100

    // Count frequencies
    for (int i = 0; i < numsSize; i++)
    {
        freq[nums[i]]++;
    }

    // Find maximum frequency
    int maxFreq = 0;
    for (int i = 1; i <= 100; i++)
    {
        if (freq[i] > maxFreq)
        {
            maxFreq = freq[i];
        }
    }

    // Sum all occurrences with maximum frequency
    int total = 0;
    for (int i = 1; i <= 100; i++)
    {
        if (freq[i] == maxFreq)
        {
            total += freq[i];
        }
    }

    return total;
}
