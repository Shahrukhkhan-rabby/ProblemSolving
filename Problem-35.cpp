#include <iostream>
using namespace std;

class Solution
{
public:
    int maxBottlesDrunk(int numBottles, int numExchange)
    {
        int drunk = 0;
        int empty = 0;

        // drink all initial bottles
        drunk += numBottles;
        empty += numBottles;

        // keep exchanging as long as possible
        while (empty >= numExchange)
        {
            empty -= numExchange; // give away empty bottles
            numExchange++;        // exchange requirement increases
            drunk++;              // got 1 new bottle, drink it
            empty++;              // that bottle becomes empty
        }

        return drunk;
    }
};

int main()
{
    Solution sol;
    cout << sol.maxBottlesDrunk(13, 6) << endl; // Output: 15
    cout << sol.maxBottlesDrunk(10, 3) << endl; // Output: 13
    return 0;
}
