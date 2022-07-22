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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) 
    {
        int mx=0,mn=INT_MAX,x=-1,p=-1,len=0;
        ListNode *prev=head;
        head=head->next;
        while(head->next!=NULL)
        {
            len++;
            if((head->val>prev->val and head->val>head->next->val) or (head->val<prev->val and head->val<head->next->val))
            {
                if(x==-1)
                    x=len;
                else
                {
                    if(p==-1)
                        mn=min(mn,len-x);
                    else
                        mn=min(mn,len-p);
                    p=len;
                }
            }
            prev=head;
            head=head->next;
        }
        if(p==-1)
            return vector<int>{-1,-1};
        else
            return vector<int>{mn,p-x};
    }
};