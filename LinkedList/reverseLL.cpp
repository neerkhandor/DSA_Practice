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
#include<stack>
class Solution {
public:
    ListNode* reverseRec(ListNode* head,ListNode* prev,ListNode* curr){
        if(curr==nullptr){
            return prev;
        }
        ListNode* forward=curr->next;
        curr->next=prev;
        // prev=curr;
        // curr=forward;
        return reverseRec(head,curr,forward);
    }
    ListNode* reverseList(ListNode* head) {
        // stack<int>st;
        // ListNode* temp=head;
        // while(temp!=nullptr){
        //     st.push(temp->val);
        //     temp=temp->next;
        // }
        // temp=head;
        // while(temp!=nullptr){
        //     temp->val=st.top();
        //     st.pop();
        //     temp=temp->next;
        // }
        // return head;
        // recursive solution
        // ListNode* prev=NULL;
        // ListNode* curr=head;
        // head = reverseRec(head,prev,curr);
        // return head;
        // iterative solution
        ListNode* prev=NULL;
        ListNode*curr=head;
        ListNode*forward=NULL;
        while(curr!=nullptr){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
};