#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool isNumber(string s)
    {
        bool seenDigit = false, seenDot = false, seenExp = false;
        bool digitAfterExp = true; // track digits after exponent

        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];

            if (isdigit(c))
            {
                seenDigit = true;
                if (seenExp)
                    digitAfterExp = true;
            }
            else if (c == '+' || c == '-')
            {
                // sign allowed only at start or just after e/E
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }
            else if (c == '.')
            {
                // dot not allowed after exponent or multiple times
                if (seenDot || seenExp)
                    return false;
                seenDot = true;
            }
            else if (c == 'e' || c == 'E')
            {
                // exp not allowed multiple times, must follow digit
                if (seenExp || !seenDigit)
                    return false;
                seenExp = true;
                digitAfterExp = false; // reset, need digits after e
            }
            else
            {
                return false; // invalid character
            }
        }

        return seenDigit && digitAfterExp;
    }
};

int main()
{
    Solution sol;
    cout << boolalpha;
    cout << sol.isNumber("0") << endl;       // true
    cout << sol.isNumber("e") << endl;       // false
    cout << sol.isNumber(".") << endl;       // false
    cout << sol.isNumber("53.5e93") << endl; // true
    cout << sol.isNumber("99e2.5") << endl;  // false
    return 0;
}
