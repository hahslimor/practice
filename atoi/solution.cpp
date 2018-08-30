#include <iostream>
#include <vector>
#include <ostream>
#include <limits>
#include <string>
#include <unordered_map>
#include <iterator>

using namespace std;
class Solution {
public:

    bool rollOver(int n, int delta) {
        numeric_limits<int> int32_limit;
        if (n == 0) {
            return false;
        }
        int how_many_times = (int32_limit.max() - delta)/n;
        if (how_many_times < 10) {
            return true;
        }
        return false;
    }
    int myAtoi(string str) {
        bool clear_leading = true, check_sign = true, found_digits = false, negative = false;
        int value = 0, delta;
        numeric_limits<int> int32_limit;
        for (string::const_iterator i=str.cbegin(); i != str.cend(); ++i) {
            if (clear_leading && *i == ' ') {
                continue;
            }
            clear_leading = false;
            if (check_sign && (*i == '-' || *i == '+')) {
                if (*i == '-') {
                    negative = true;;
                }
                check_sign = false;
                continue;
            }     
            check_sign = false;
            if (*i < '0' ||  *i > '9') {
                if (!found_digits) {
                    value = 0;
                }
                break;
            }
            found_digits = true;

            delta = (*i - '0');
            if (!rollOver(value, delta)) {
                value = value * 10 + delta;
            } else {
                if (negative) {
                    value = int32_limit.min();
                    negative = false;
                } else {
                    value = int32_limit.max();
                }
                break;
            }
        }
        if (negative) {
            value = -value;
        }
        return value;
    }
};

int main() {
    class Solution s;
   // cout << "Number: " << s.myAtoi(string("-91283472332")) << endl;
    cout << "Number: " << s.myAtoi(string("2147483648")) << endl;
    return 0;
}
