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
    void deleteNode(ListNode* node) 
    {
        ListNode *temp=node->next;
        node->val=temp->val;
        if(temp->next!=NULL)
            node->next=temp->next;
        else
            node->next=NULL;
        delete(temp);
    }
};