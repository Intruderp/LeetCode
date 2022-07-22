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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            len++;
            temp=temp->next;
        }
        int x=len/k,r=len%k;
        vector<ListNode*> res;
        while(res.size()!=k)
        {
            res.push_back(head);
            ListNode* prev=head;
            len=x+(r>0 ? 1:0);
            r--;
            while(head!=NULL and len--)
            {
                prev=head;
                head=head->next;
            }
            if(prev!=NULL)
                prev->next=NULL;
        }
        return res;
    }
};