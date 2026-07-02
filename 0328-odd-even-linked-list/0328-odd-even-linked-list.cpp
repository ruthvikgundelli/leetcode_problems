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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* remainingHalf = head->next;
        ListNode* odd = head;
        ListNode* even = remainingHalf;
        ListNode* temp = head;
        while(odd != nullptr && odd->next != nullptr){
            odd = odd->next->next;
            if(odd != nullptr){
                temp->next = odd;
                temp = odd;
                even->next = odd->next;
                even = odd->next;
            }
        }
        if(odd == nullptr) temp->next = remainingHalf;
        else odd->next = remainingHalf;
        return head;
    }
};