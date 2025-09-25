#include <iostream>
using namespace std;

int main()
{
    int u, a, t;
    while (cin >> u >> a >> t)
    { // keep reading until EOF
        int v = u + (a * t);
        cout << v << endl;
    }
    return 0;
}
