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
    int getLength(ListNode* head){
        if(head==nullptr){
            return 0;
        }
        if(head->next==nullptr){
            return 1;
        }
        ListNode*temp=head;
        int len=0;
        while(temp!=nullptr){
            len++;
            temp=temp->next;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // int len=getLength(head);
        // // if n== size of ll
        // if(len==n){
        //     ListNode* newNode=head->next;
        //     return newNode;
        // }
        // ListNode*temp=head;
        // int res=len-n;
        // while(temp!=nullptr){
        //     res--;
        //     if(res==0){
        //         break;
        //     }
        //     temp=temp->next;
        // }
        // ListNode* delNode=temp->next;
        // temp->next=delNode->next;
        // delete delNode;
        // return head;
        ListNode*fast=head;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        if(fast==nullptr){
            return head->next;
        }
        ListNode*slow=head;
        while(fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* delNode=slow->next;
        slow->next=delNode->next;
        delete delNode;
        return head;
    }
};