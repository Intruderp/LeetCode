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
    ListNode* reverse(ListNode* head)
    {
        ListNode *prev=NULL,*temp;
        while(head!=NULL)
        {
            temp=head->next;
            head->next=prev;
            prev=head;
            head=temp;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        int res=0;
        ListNode *slow=head,*fast=head;
        while(fast!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* temp=slow;
        slow=reverse(slow);
        while(slow!=NULL)
        {
            res=max(res,head->val+slow->val);
            head=head->next;
            slow=slow->next;
        }
        return res;
    }
};