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
    bool isPalindromeWorker(ListNode* tail, size_t list_count, ListNode** head, size_t *processed) {
        if (!tail) {
            return true;
        }
        bool isPalindrome = isPalindromeWorker(tail->next, list_count+1, head, processed);
        cout << " isPalindrome: " << isPalindrome << " list_count : " << list_count << " processed : " << *processed << endl;
        if (!isPalindrome || list_count == *processed) {
            *processed = *processed - 1;
            return isPalindrome;
        }
        *processed += 1;
        if (tail->val == (*head)->val) {
            *head = (*head)->next;
            return true;
        }
        return false;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }
        ListNode *cur_head = head;
        size_t processed_count = 0;
        return isPalindromeWorker(head, 1, &cur_head, &processed_count); 
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
    head1[3].next = NULL;
    cout << "\nList: ";
    s.printList(head1);
    cout << "\nIs palindrome: " << s.isPalindrome(head1) << endl;
    return 0;
}
