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
    ListNode* reverseLL(ListNode *head){
        if(head->next == nullptr) return head;
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while(head != nullptr){
            head = head->next;
            temp->next = prev;
            prev = temp;
            temp = head;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        while(fast != nullptr && fast->next != nullptr){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        slow = reverseLL(slow);
        fast = slow;
        prev = head;
        ListNode* temp = head;
        while(prev != nullptr && fast != nullptr){
            prev = prev->next;
            fast = fast->next;
            temp->next = slow;
            if(prev != nullptr) slow->next = prev;
            temp = prev;
            slow = fast;
        }
    }
};