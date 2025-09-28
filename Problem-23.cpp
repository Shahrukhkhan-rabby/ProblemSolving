#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> result;
        if (words.empty() || s.empty())
            return result;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if (s.size() < totalLen)
            return result;

        unordered_map<string, int> wordFreq;
        for (auto &w : words)
            wordFreq[w]++;

        // Check each possible offset
        for (int i = 0; i < wordLen; i++)
        {
            int left = i, count = 0;
            unordered_map<string, int> window;

            for (int j = i; j + wordLen <= s.size(); j += wordLen)
            {
                string word = s.substr(j, wordLen);

                if (wordFreq.find(word) != wordFreq.end())
                {
                    window[word]++;
                    count++;

                    // Shrink if word count exceeded
                    while (window[word] > wordFreq[word])
                    {
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    // Found valid window
                    if (count == wordCount)
                    {
                        result.push_back(left);
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                }
                else
                {
                    // reset window
                    window.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }
        return result;
    }
};
