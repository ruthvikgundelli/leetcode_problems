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
    ListNode* findMiddle(ListNode* temp){
        ListNode* fast = temp;
        ListNode* slow = temp;
        ListNode* prev = nullptr;
        while(fast != nullptr && fast->next != nullptr){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast == nullptr) slow = prev;
        return slow;
    }
    ListNode* mergeLL(ListNode* leftHead, ListNode* rightHead){
        if (leftHead == nullptr) return rightHead;
        if (rightHead == nullptr) return leftHead;
        ListNode* mergedList = new ListNode();
        ListNode* tail = mergedList;
        while (leftHead != nullptr && rightHead != nullptr) {
            if (leftHead->val <= rightHead->val) {
                tail->next = leftHead;
                leftHead = leftHead->next;
            } else {
                tail->next = rightHead;
                rightHead = rightHead->next;
            }
            tail = tail->next;
        }
        if (leftHead != nullptr) tail->next = leftHead;
        else tail->next = rightHead;
        return mergedList->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* mid = findMiddle(head);
        ListNode* leftHead = head;
        ListNode* rightHead = mid->next;
        mid->next = nullptr;
        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);
        return mergeLL(leftHead,rightHead);
    }
};