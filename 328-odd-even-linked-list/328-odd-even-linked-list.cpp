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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL or head->next==NULL)
            return head;
        ListNode *head2=head->next,*res=head,*res2=head2;
        while(true)
        {
            head->next=head2->next;
            if(head2->next!=NULL)
                head2->next=head->next->next;
            head2=head2->next;
            if(head2==NULL)
            {
                if(head->next!=NULL)
                    head=head->next;
                head->next=res2;
                break;
            }
            head=head->next;
        }
        return res;
    }
};