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
    ListNode* reverse(ListNode* head){
        ListNode*prev=NULL;
        ListNode* curr=head;
        ListNode* forward=NULL;
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        // stack<int>st;
        // ListNode*temp=head;
        // while(temp!=nullptr){
        //     st.push(temp->val);
        //     temp=temp->next;
        // }
        // temp=head;
        // while(temp!=nullptr){
        //     if(st.top()!=temp->val){
        //         return false;
        //     }
        //     st.pop();
        //     temp=temp->next;
    // }
        // we have to do in the given ll without using extra space
        // its not doubly ll so i cant go in reverse order
        // we will use hare tortoise approach
        ListNode*temp=head;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL){
            fast=fast->next;
            if(fast->next!=NULL){
                slow=slow->next;
                fast=fast->next;
            }
        }
        // slow will be pointing to the middle node
         ListNode* newHead=reverse(slow->next);
         while(newHead!=nullptr){
             if(temp->val!=newHead->val){
                 reverse(newHead);
                 return false;
             }
             temp=temp->next;
             newHead=newHead->next;
        }
        reverse(newHead);
        return true;
    }
};