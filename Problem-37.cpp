#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> res;
        int n = words.size();
        int i = 0;

        while (i < n)
        {
            int j = i, lineLen = 0;

            // Find how many words fit in this line
            while (j < n && lineLen + words[j].size() + (j - i) <= maxWidth)
            {
                lineLen += words[j].size();
                j++;
            }

            int gaps = j - i - 1;
            string line;

            // Last line OR only one word → left-justified
            if (j == n || gaps == 0)
            {
                for (int k = i; k < j; k++)
                {
                    line += words[k];
                    if (k < j - 1)
                        line += " ";
                }
                // Fill remaining spaces
                line += string(maxWidth - line.size(), ' ');
            }
            else
            {
                // Full justification
                int totalSpaces = maxWidth - lineLen;
                int spacePerGap = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;

                for (int k = i; k < j; k++)
                {
                    line += words[k];
                    if (k < j - 1)
                    {
                        int spaces = spacePerGap + (extraSpaces-- > 0 ? 1 : 0);
                        line += string(spaces, ' ');
                    }
                }
            }

            res.push_back(line);
            i = j; // Move to next line
        }

        return res;
    }
};

int main()
{
    Solution sol;

    vector<string> words1 = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth1 = 16;
    auto res1 = sol.fullJustify(words1, maxWidth1);
    for (auto &line : res1)
        cout << '"' << line << '"' << endl;

    cout << "----" << endl;

    vector<string> words2 = {"What", "must", "be", "acknowledgment", "shall", "be"};
    int maxWidth2 = 16;
    auto res2 = sol.fullJustify(words2, maxWidth2);
    for (auto &line : res2)
        cout << '"' << line << '"' << endl;

    return 0;
}
