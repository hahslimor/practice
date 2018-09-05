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

class Solution {
public:
    ListNode* reverseList_internal(ListNode *head) {
         if (!head) {
            return head;
        }
        ListNode *cur = reverseList_internal(head->next);
        if (head) {
            head->next = NULL;
        }
        if (cur) {
            cur->next = head;
        }
        return head;        
    } 

    ListNode* reverseList(ListNode* head) {
        ListNode *new_head = head, *temp = head;
        if (!head || !head->next) {
            return head;
        }
        while (temp->next) {
            new_head = temp->next;
            temp = temp->next;
        }
        ListNode *last_node = reverseList_internal(head);
        return new_head;
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
    struct ListNode head[10];
    size_t i=0;
    for (; i<sizeof(head)/sizeof(head[0]); i++) {
        head[i].val = i;
        head[i].next = &head[i+1];
    }
    head[i - 1].next = NULL;
    cout << "\nList: ";
    s.printList(head);
    struct ListNode *reversed_list = s.reverseList(head);
    cout << "\nReverse list: " ;
    s.printList(reversed_list);
    cout << endl;
    return 0;
}
