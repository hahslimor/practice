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
public:
    bool isLREqual(TreeNode *left, TreeNode *right) {
        if (!left && !right) {
            return true;
        }
        if (!left || !right) {
            return false;
        }
        if (left->val != right->val) {
            return false;
        }
        return isLREqual(left->left, right->right) && isLREqual(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        return isLREqual(root->left, root->right);
    }
};

int main() {
    class Solution s;
    struct ListNode head1[10], head2[5];
    head1[0].val = 1;
    head1[1].val = 3;
    head1[2].val = 2;
    head1[3].val = 1;
    head1[0].next = &head1[1];
    head1[1].next = &head1[2];
    head1[2].next = &head1[3];
    //head1[3].next = &head1[1];
    head1[3].next = NULL;
    //cout << "\nList: ";
    //s.printList(head1);
    cout << "\nHas cycle: " << s.hasCycle(head1) << endl;
    return 0;
}
