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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* curr = dummy;
        int carry = 0;
        while(t1 != nullptr || t2 != nullptr){
            if(t1 != nullptr) carry = carry + t1->val;
            if(t2 != nullptr) carry = carry + t2->val;
            ListNode* temp = new ListNode(carry%10);
            curr->next = temp;
            curr = temp;
            carry /= 10;
            if(t1 != nullptr) t1 = t1->next;
            if(t2 != nullptr) t2 = t2->next;
        }
        if(carry){
            ListNode* temp = new ListNode(carry%10);
            curr->next = temp;
            curr = temp;
        }
        curr = dummy->next;
        delete dummy;
        return curr;
    }
};