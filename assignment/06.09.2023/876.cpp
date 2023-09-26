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

    int getLength(ListNode* head) {

        ListNode* temp = head;
        int cnt = 0;

        while (temp) {
            
            cnt++;
            temp = temp->next;
        }

        return cnt;
    }

    ListNode* middleNode(ListNode* head) {

        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {

            fast = fast->next->next;

            head = head->next;
        }
        return head;

        /*
        int len = getLength(head);
        int lenn = len/2;

        ListNode* temp = head;

        while(lenn--) {

            temp = temp->next;
        }
        
        return temp;
        */
    }
};