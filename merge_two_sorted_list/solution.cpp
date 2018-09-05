#include <iostream>
#include <vector>
#include <ostream>
#include <limits>
#include <string>
#include <unordered_map>
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
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *merge_head = NULL;
        if (l1 && !l2) {
            return l1;
        }
        if (l2 && !l1) {
            return l2;
        }
        if (l1->val <= l2->val) {
            merge_head = l1;
            l1 = l1->next;
        } else {
            merge_head = l2;
            l2 = l2->next;
        }
        ListNode *next_merge_node = merge_head;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                next_merge_node->next = l1;
                l1 = l1->next;
            } else {
                next_merge_node->next = l2;
                l2 = l2->next;
            }
            next_merge_node = next_merge_node->next;
        }
        while (l1) {
            next_merge_node->next = l1;
            l1 = l1->next;
            next_merge_node = next_merge_node->next;
        }
        while (l2) {
            next_merge_node->next = l2;
            l2 = l2->next;
            next_merge_node = next_merge_node->next;
        }
        return merge_head;
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
    size_t i=0;
    for (; i<sizeof(head1)/sizeof(head1[0]); i++) {
        head1[i].val = i;
        head1[i].next = &head1[i+1];
    }
    head1[i - 1].next = NULL;
    for (i=0; i<sizeof(head2)/sizeof(head2[0]); i++) {
        head2[i].val = i*5;
        head2[i].next = &head2[i+1];
    }
    head2[i - 1].next = NULL;

    cout << "\nList: ";
    s.printList(head1);
    cout << "\nList2: ";
    s.printList(head2);
 
    struct ListNode *merge_list = s.mergeTwoLists(head2, head1);
    cout << "\nMerge list: " ;
    s.printList(merge_list);
    cout << endl;
    return 0;
}
