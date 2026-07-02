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
        ListNode* fast = temp->next;
        ListNode* slow = temp;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
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
        ListNode* rightHead = mid->next;
        mid->next = nullptr;
        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHead);
        return mergeLL(left,right);
    }
};