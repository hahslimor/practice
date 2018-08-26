#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        digits[digits.size() - 1] += 1;
        for (auto i = digits.rbegin(); i != digits.rend(); ++i) {
            *i = *i + carry;
            carry = (*i == 10 ? 1 : 0);
            if (carry)  {
                *i = 0;
            }
        }
        if (carry) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

int main() {
    vector<int> test = { 1, 9, 9, 9 };

    Solution s;
    s.plusOne(test);
    for (auto i : test) {
        cout << " " << i;
    }
}
