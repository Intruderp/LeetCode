/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int length(ListNode *head)
    {
        int len=0;
        while(head!=NULL)
        {
            len++;
            head=head->next;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        int l1=length(headA),l2=length(headB);
        if(l1<l2)
            swap(headA,headB);
        int x=abs(l1-l2);
        while(x--)
            headA=headA->next;
        while(headA!=NULL and headA!=headB)
        {
            headA=headA->next;
            headB=headB->next;
        }
        if(headA==headB)
            return headA;
        return NULL;
    }
};