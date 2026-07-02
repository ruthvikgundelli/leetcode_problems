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
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == head) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next !=nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow){
                slow = head;
                break;
            }
        }
        if(fast == nullptr || fast->next == nullptr) return nullptr;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};