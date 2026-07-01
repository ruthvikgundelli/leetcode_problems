/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *reverseLL(ListNode* head){
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while(temp != nullptr){
            head = head->next;
            temp->next = prev;
            prev = temp;
            temp = head;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;;
        }
        if(fast != nullptr) slow = slow->next;
        slow = reverseLL(slow);
        while(slow != nullptr){
            if(slow->val != head->val) return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
};