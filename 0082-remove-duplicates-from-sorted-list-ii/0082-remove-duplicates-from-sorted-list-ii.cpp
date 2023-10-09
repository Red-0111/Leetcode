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
    ListNode* deleteDuplicates(ListNode* head) {
            if (!head || !head->next)
            return head;

        ListNode* temp = head;
        ListNode* prev=NULL;
        map<int, int> mp;

        while (temp) {
            mp[temp->val]++;
            temp = temp->next;
        }

        temp = head;
        while (temp && head) 
        {
            if (mp[temp->val] > 1)
            {
                if(prev==NULL)
                {
                    head=head->next;
                    temp=temp->next;
                }
                else{
                    prev->next=temp->next;
                    temp=temp->next;   
                }
            }
            else{
                prev=temp;
                temp=temp->next;
            }
               
            
        }

        return head;    
    }
};