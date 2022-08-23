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
    void print(ListNode* head)
    {
        while(head!=NULL)
        {
            cout<<head->val<<' ';
            head=head->next;
        }
        cout<<endl;
    }
    bool isPalindrome(ListNode* head) 
    {
        ListNode *slow=head,*fast=head;
        while(fast->next!=NULL and fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverse(slow->next);
        ListNode *ptr1=head,*ptr2=slow->next;
        while(ptr2!=NULL)
        {
            if(ptr1->val!=ptr2->val)
                return false;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        return true;
    }
};