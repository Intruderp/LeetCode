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
    ListNode* reverse(ListNode* head,ListNode* prev,ListNode* c)
    {
        if(head==c)
            return prev;
        ListNode *temp=reverse(head->next,head,c);
        head->next=prev;
        return temp;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        ListNode *a=head,*c=head;
        int l=left;
        while(left-->1)
            a=a->next;
        while(right--)
            c=c->next;
        ListNode *b=reverse(a,NULL,c);
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