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
        if(!head||!head->next) return head;
        ListNode* tmp=head;
        ListNode* prev=NULL;
        map<int,int> mp;
        while(tmp)
        {
            mp[tmp->val]++;
            tmp=tmp->next;
        }
        tmp=head;
        while(tmp&&head)
        {
            if(mp[tmp->val]>1)
            {
                if(prev==NULL)
                {
                    head=head->next;
                    tmp=tmp->next;
                }
                else
                {
                    prev->next=tmp->next;
                    tmp=tmp->next;
                }
            }
            else
            {
                prev=tmp;
                tmp=tmp->next;
            }
        }
        return head;
    }
};