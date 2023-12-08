#include <stack>
/*

Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next,*prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev= NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
        this->prev= NULL;
    }
    Node(int data, Node* next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev= prev;
    }
};

*/

Node* reverseDLL(Node* head)
{   // naive solution
    // generally we store data in linked list what if i can
    // change th data 
    // we can use stack data structure as it has lifo property
    // we dont want to temper the head so we will have a temp variable
    // push the value into the stack and then do one more traversal
    // thats the reason i didnt temper the head
    // so in this way i will reverse the data not ptrs
    // tc->O(2n)
    // sc->O(n)
    // if(head==nullptr || head->next==nullptr){
    //     return head;
    // }
    // Node*temp=head;
    // stack<int>st;
    // while(temp!=nullptr){
    //     st.push(temp->data);
    //     temp=temp->next;
    // } 
    // temp=head;
    // while(temp!=nullptr){
    //     temp->data=st.top();
    //     st.pop();
    //     temp=temp->next;
    // }
      
    // return head;


    // it is 2 pass solution we have to find a solution where we can reverse in single pass
    // so swapping data is now not possible but i can reverse links
    // there are two pointer next and back
    // when we will swap it the next will point to back and back will point to next
    // so i have to swap the next and back pointer
    // temp=a
    // a=b
    // b=temp
    // similar logic
    // i can do like 
    // curr->next=last
    // curr->last=next
    // but i wont do this it requires two variables i can do using single variable
    // last=curr->back  
    // curr->back=curr->next
    // curr->next=last
    // in second step curr->back value is over written thats why we stored it in last
    // we are not having curr->next pointer while traversing so we will do curr=curr->back
    // tc->O(n)
    // sc->O(1)
    // show how was your thought process from considering one node 
    // and swapping formula and thought of 3rd variable
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    Node*last=nullptr;
    Node*curr=head;

    while(curr!=nullptr){
        last=curr->prev;
        curr->prev=curr->next;
        curr->next=last;
        curr=curr->prev;
    }
    return last->prev;
}