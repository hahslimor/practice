#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        size_t count = 0;
        int insert_at = 0;

        for (int i=0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                count++;
            } else {
                if (count > 0 && (insert_at != i)) {
                    nums[insert_at] = nums[i];
                    nums[i] = 0;
                }
                insert_at++;
            }
        }
    }
};

int main() {
    class Solution s;
    vector<int> test = { 1, 1 , 1 , 1 };
    s.moveZeroes(test);
    for (auto i : test) {
        cout << " " << i ;
    }
}
