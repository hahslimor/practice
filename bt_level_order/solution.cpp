#include <iostream>
#include <vector>
#include <ostream>
#include <limits>
#include <string>
#include <unordered_set>
#include <queue>

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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> lr_queue;
        vector<vector<int>> lr_list;

        if (!root) {
            return lr_list;
        }
        lr_queue.push(root);
        int cur_level_count = lr_queue.size(), nodes_at_this_level = 0;
        int index = 0;
        while (!lr_queue.empty()) {
            nodes_at_this_level = lr_queue.size();
            vector<int> this_level;
            for (size_t i=0; i<nodes_at_this_level; i++) {
                TreeNode* front = lr_queue.front();
                lr_queue.pop();
                this_level.push_back(front->val);
                if (front->left) {
                    lr_queue.push(front->left);
                }
                if (front->right) {
                    lr_queue.push(front->right);
                }
            }
            lr_list.push_back(this_level);
            index++;
        }
        return lr_list;
    }

    TreeNode *BuildTree(vector<int> &values) {
        TreeNode *root = nullptr, *cur;
        int child_index;
        queue<TreeNode *> t_q;
        t_q.push(new TreeNode(values[0]));

        for (int i=0; i<values.size(); i++) {
            if (values[i] == -1) {
                continue;
            }
            cur = t_q.front();
            t_q.pop();
            if (!root) {
                root = cur;
            }
            child_index = i*2 + 1;
            if (child_index + 1 >= values.size()) {
                break;
            }
            cur->left = ((values[child_index] != -1) ? new TreeNode(values[child_index]) : nullptr);
            cur->right = ((values[child_index+1] != -1) ? new TreeNode(values[child_index+1]) : nullptr);
            if (cur->left) {
                t_q.push(cur->left);
            }
            if (cur->right) {
                t_q.push(cur->right);
            }
        }
        return root;
    }

    void PrintTree(TreeNode *root) {
        if (!root) {
            cout << " NULL ";
            return;
        }
        cout << " " << root->val;
        PrintTree(root->left);
        PrintTree(root->right);
    }
};

int main() {
    class Solution s;
    //vector<int> test = {3,9,20,-1,-1,15,7};
    vector<int> test = {1, 2, -1, 3, -1, -1, -1, 4, -1 };
    TreeNode *root = s.BuildTree(test);
    s.PrintTree(root);
    cout << endl << "Level Order : " <<  endl;
    vector<vector<int>> ans = s.levelOrder(root);
    for (auto i: ans) {
        for (auto j: i) {
            cout << " " << j;
        }
        cout << endl;
    }
    return 0;
}
