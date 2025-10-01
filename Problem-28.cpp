#include <iostream>
using namespace std;

class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int total = numBottles; // total bottles drunk
        int empty = numBottles; // empty bottles after drinking

        while (empty >= numExchange)
        {
            int newBottles = empty / numExchange;     // exchange empties for new full bottles
            total += newBottles;                      // drink them
            empty = empty % numExchange + newBottles; // remaining empties + new empties
        }

        return total;
    }
};

int main()
{
    Solution sol;
    cout << sol.numWaterBottles(9, 3) << endl;  // 13
    cout << sol.numWaterBottles(15, 4) << endl; // 19
    return 0;
}
