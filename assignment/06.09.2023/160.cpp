/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {

private:
    int getLength(ListNode* head) {
        
        int len = 0;
        ListNode* temp = head;

        while (temp) {
            len++;
            temp = temp->next;
        }

        return len;
    }


public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        int l1 = getLength(headA);
        int l2 = getLength(headB);
        int diff = 0;

        if (l1 > l2) {
            diff = l1 - l2;

            while (diff--) {
                headA = headA->next;
            }
        }

        if (l2 > l1) {
            diff = l2 - l1;

            while (diff--) {
                headB = headB->next;
            }
        }
        
        while (headA != headB) {

            headA = headA->next;
            headB = headB->next;
        }

        return headA;        
    }
};