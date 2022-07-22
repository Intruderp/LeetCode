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
    ListNode* partition(ListNode* head, int x) {
        ListNode *before=new ListNode(-1);
        ListNode *after=new ListNode(-1);
        ListNode *p=before,*p2=after;
        while(head)
        {
            if(head->val<x)
            {
                before->next=head;
                before=head;
            }
            else
            {
                after->next=head;
                after=head;
            }
            head=head->next;
        }
        before->next=p2->next;
        after->next=NULL;
        return p->next;
    }
};