#include <iostream>
#include <vector>
#include <ostream>
#include <limits>
#include <string>
#include <unordered_set>
#include <iterator>

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
     ListNode() : val(0), next(NULL) {}
 };

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    unordered_set<ListNode *> seen_nodes;

public:
    bool hasCycle(ListNode *head) {
        if (!head) {
            return false;
        }
        if (seen_nodes.find(head) == seen_nodes.end()) {
            seen_nodes.insert(head);
        } else {
            return true;
        } 

        bool cycle_found = hasCycle(head->next);
        return cycle_found;
    }

    void printList(ListNode *head) {
        ListNode *temp = head;

        while (temp) {
            cout << " " << temp->val;
            temp = temp->next;
        }
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
