/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* sortList(Node *head){
    // Write your code here.
    // tc->O(2n)
    // two passes
    // int cnt0=0;
    // int cnt1=0;
    // int cnt2=0;
    // Node*temp=head;
    // while(temp!=nullptr){
    //     if(temp->data==0){
    //         cnt0++;
    //     }
    //     else if(temp->data==1){
    //         cnt1++;
    //     }
    //     else {
    //         cnt2++;
    //     }
    //     temp=temp->next;
    // }
    // at this step we have count of 0,1,2 in their respective variables
    // temp=head;
    // while(temp!=nullptr){
    //     if(cnt0){
    //         temp->data=0;
    //         cnt0--;
    //     }
    //     else if(cnt1){
    //         temp->data=1;
    //         cnt1--;
    //     }
    //     else if (cnt2){
    //         temp->data=2;
    //         cnt2--;
    //     }
    //     temp=temp->next;
    // }
    // return head;
    // if i change the links than we can do it in single pass
    // i will have dummy nodes for 0,1,2
    // tc->O(n)
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    Node*zero=new Node(-1);
    Node*one=new Node(-1);
    Node*two=new Node(-1);
    Node*zeroHead=zero;
    Node*oneHead=one;
    Node*twoHead=two;
    
    Node*temp=head;
    while(temp!=nullptr){
        if(temp->data==0){
            zeroHead->next=temp;
            zeroHead=zeroHead->next;
        }
        else if (temp->data==1){
            oneHead->next=temp;
            oneHead=oneHead->next;
        }
        else{
            twoHead->next=temp;
            twoHead=twoHead->next;
        }
        temp=temp->next;
    }
    // now the main task comes zeroHead->next should be pointing to one->next
    // and oneHead should be pointing to two->next
    // what if i dont have one 
    zeroHead->next=(one->next)?one->next:two->next;
    // what if there are no twos than in that case two->next will alreaddy be pointing to null
    // if there are no zero then zero will be connecting to oneHead
    oneHead->next=two->next;
    // if there are no ones than one
    twoHead->next=nullptr;
    Node*newHead=zero->next;
    delete zero;
    delete one;
    delete two;
    return newHead;
}