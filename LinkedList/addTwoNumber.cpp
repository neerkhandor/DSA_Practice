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
    // we start from unit place the number is giving in reverse order so we dont have to reverse it bcoz we already have reverse list and we start from units place
    // we traverse and add them into a new node
    // sum list also have to be in reverse order
    // initially i will assign a dummmy node 
    // i will use curr to traverse the sum list it will form the sum
    // curr points to new node 
    // we will also have two temp variables to traverse the two list
    // when we use the concept of dummmy nodes than immplementation becomes very simple
    // whenever we have to create new list where we have to store result of something always prefer the concept of Dummy NODE
    // tc->O(max(l1,l2))
    // sc->O(1) if want to store the result than O(max(l1,l2))
    ListNode* func(ListNode* head1, ListNode* head2){
        ListNode*temp1=head1;
        ListNode*temp2=head2;
        ListNode*dummyNode=new ListNode(-1);
        ListNode*curr=dummyNode;
        int carry=0;
        while(temp1!=nullptr || temp2!=nullptr){
            int sum=carry;
            if(temp1) sum=sum+temp1->val;
            if(temp2) sum=sum+temp2->val;
            ListNode *newNode=new ListNode(sum%10);
            carry=sum/10;
            curr->next=newNode;
            curr=curr->next;
            if(temp1) temp1=temp1->next;
            if(temp2) temp2=temp2->next;
        }
        if(carry){
            ListNode *newNode=new ListNode(carry);
            curr->next=newNode;
        }
        return dummyNode->next;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return func(l1,l2);
    }
};