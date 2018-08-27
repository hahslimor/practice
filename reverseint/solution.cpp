#include <iostream>
#include <vector>
#include <ostream>
#include <limits>

using namespace std;

class Solution {
public:
    int32_t reverse(int32_t x) {
        int32_t reverse_x = 0;
        int32_t cur_digit, orig_x = x;
        numeric_limits<int32_t> maxint32t;
        while ( x != 0 ) {
            cur_digit = abs(x % 10);
            cout << " cur_digit " << cur_digit << " reverse_x " << reverse_x << " reverse_x*10 + \
cur_digit " << (int32_t)(reverse_x*(int32_t)10 + cur_digit) << endl;
            if ( reverse_x && ((maxint32t.max() - reverse_x)/reverse_x  < 9 )) {
                reverse_x = 0;
                break;
            }
            reverse_x = reverse_x*10 + cur_digit;
            x = x / 10;
        }
        if (orig_x < 0) {
            reverse_x *= -1;
        }
        return reverse_x;
    }
};

int32_t main() {
    class Solution s;
    //int32_t x = -2147483648;
    int32_t x = -901000;
    //int32_t x = 123;
    cout << "reverse " << x << endl;
    int32_t ans = s.reverse(x);
    cout << ans ;
    return 0;
}
