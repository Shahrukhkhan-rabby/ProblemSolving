#include <string>
#include <unordered_map>
#include <cstdlib>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string res;

        // Determine the sign
        if ((numerator < 0) ^ (denominator < 0)) res += "-";

        // Convert to long long to prevent overflow
        long long n = llabs((long long)numerator);
        long long d = llabs((long long)denominator);

        // Integer part
        res += to_string(n / d);
        long long remainder = n % d;
        if (remainder == 0) return res;

        res += ".";
        unordered_map<long long, int> remainderMap;

        // Fractional part
        while (remainder != 0) {
            if (remainderMap.count(remainder)) {
                res.insert(remainderMap[remainder], "(");
                res += ")";
                break;
            }
            remainderMap[remainder] = res.size();
            remainder *= 10;
            res += to_string(remainder / d);
            remainder %= d;
        }

        return res;
    }
};
