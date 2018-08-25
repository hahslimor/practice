#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        size_t num1_size = nums1.size();
        size_t num2_size = nums2.size();
        vector<int> intersection;

        unordered_map<int, int> nums_dict;

        for (auto i : nums1) {
            nums_dict[i]++;
        }

        for (auto i: nums2) {
            if (nums_dict[i] > 0) {
                intersection.push_back(i);
                nums_dict[i]--;
            }
        }
        return intersection;
    }
};


int main() {
    vector<int> test1 = { 1, 2, 3, 4 };
    vector <int> test2 = { 2, 3 };

    class Solution s;
    vector<int> intersection = s.intersect(test1, test2);

    for (auto i: intersection) {
        cout << " " << i ;
    }
    cout << "\n";
}
