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
        vector<int> val;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            val.push_back(temp->val);
            temp=temp->next;
        }
        temp=head;
        for(auto &v:val)
        {
            if(v<x)
            {
                temp->val=v;
                temp=temp->next;
            }
        }
        for(auto &v:val)
        {
            if(v>=x)
            {
                temp->val=v;
                temp=temp->next;
            }
        }
        return head;
    }
};