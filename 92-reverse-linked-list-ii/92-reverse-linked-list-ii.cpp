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
    ListNode* reverse(ListNode* head,ListNode* c)
    {
        ListNode *temp,*prev=NULL;
        while(head!=c)
        {
            temp=head->next;
            head->next=prev;
            prev=head;
            head=temp;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        ListNode *a=head,*c=head;
        int l=left;
        while(left-->1)
            a=a->next;
        while(right--)
            c=c->next;
        ListNode *b=reverse(a,c);
        a->next=c;
        if(l==1)
            return b;
        else
        {
            ListNode* temp=head;
            while(l-->2)
                temp=temp->next;
            temp->next=b;
            return head;
        }
    }
};