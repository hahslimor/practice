#include <iostream>
#include <vector>
#include <ostream>
#include <limits>

using namespace std;

int32_t main() {
     int32_t x = 2147483646; // 2 ^32 -2
    //int32_t x = 1056389759;
    //int32_t x = 123;
    class numeric_limits<int32_t> maxint32;
    cout << "x " << x << endl;
    cout << "x * 10 " << (x/maxint32.max() < 10 ? "overflow" : "good") << endl;
    cout << " x + 2 " << x + 2 << endl;
    return 0;
}
