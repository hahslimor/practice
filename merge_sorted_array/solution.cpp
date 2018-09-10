#include <iostream>
#include <vector>
#include <ostream>
#include <limits>
#include <string>
#include <unordered_set>
#include <iterator>

using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void shift_vect_by_one(vector<int>& nums, int index, int end_index) {
        for (int i=end_index; i>=index ; i--) {
            nums[i+1] = nums[i]; 
        }
    }
public:
     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) {
            return;
        }
        int nums1_insert_at = nums1.size() - 1;
        int nums2_index = nums2.size() - 1;
        int nums1_index = m -1;
        for (int i=(n-1); i>=0; i--) {
            while(nums1_index >= 0 && nums2[i] < nums1[nums1_index]) {
                nums1_index--;
            }
            if (nums1_index == -1 || nums1_index < (m - 1)) {
                shift_vect_by_one(nums1, nums1_index + 1, m - 1);
                nums1[nums1_index + 1] = nums2[i];
            } else {
                nums1[m] = nums2[i];
            }
            m++;
        }
    }
};

int main() {
    class Solution s;
    vector<int> nums1 = { 8,10,12, 0, 0, 0};
    vector<int> nums2 = {1,2, 13};
    s.merge(nums1, nums2.size(), nums2, nums2.size());
    for (auto i : nums1) {
        cout << " " << i;
    }
    cout << endl;
    return 0;
}
