#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        if (numerator == 0)
            return "0";

        string result;

        // Check for negativity
        if ((numerator < 0) ^ (denominator < 0))
            result += "-";

        // Use long long to avoid overflow
        long long n = llabs((long long)numerator);
        long long d = llabs((long long)denominator);

        // Append integer part
        result += to_string(n / d);
        long long remainder = n % d;

        if (remainder == 0)
            return result;

        result += ".";

        unordered_map<long long, int> remainderIndex;
        while (remainder != 0)
        {
            if (remainderIndex.find(remainder) != remainderIndex.end())
            {
                result.insert(remainderIndex[remainder], "(");
                result += ")";
                break;
            }

            remainderIndex[remainder] = result.size();
            remainder *= 10;
            result += to_string(remainder / d);
            remainder %= d;
        }

        return result;
    }
};
