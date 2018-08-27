#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map;

        for (auto i=0; i<nums.size(); ++i) {
            num_map.insert({nums[i], i});
        }

        vector<int> two_elements;
        int first, second;
        unordered_map<int, int>::iterator found;
        for (auto i=0; i<nums.size(); i++) {
            first = i;
            found = num_map.find(target-nums[i]);
            if (found != num_map.end()) {
                if (found->second != first) {
                    second = found->second;
                    break;
                }
            }
            first = 0;
            second = 0;
        }
        two_elements.push_back(first);
        two_elements.push_back(second);
        return two_elements;
    }
};

int main() {
    class Solution s;
    vector<int> test = {  3,2, 4};
    vector<int> ans = s.twoSum(test, 6);
    for (auto i : ans) {
        cout << "  " << i;
    }
}
