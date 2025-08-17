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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||!head->next||k==0) return head;
        ListNode* end=head; int n=1;
        while(end->next)
        {
            n++;
            end=end->next;
        }
        k=k%n;
        int stepstonewhead=n-k;
        end->next=head;
        ListNode* newtail=end;
        while(stepstonewhead--)
        {
            newtail=newtail->next;
        }
        ListNode* newhead=newtail->next;
        newtail->next=NULL;
        return newhead;
    }
};