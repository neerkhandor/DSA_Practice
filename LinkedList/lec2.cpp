#include<iostream>
#include<vector>
using namespace std;
// doubly linked list
// data,next node and prev node
class Node{
    public:
    int data;
    Node*prev;
    Node*next;
    Node(int data,Node*prev,Node*next){
        this->data=data;
        this->prev=prev;
        this->next=next;
    }
    Node(int data){
        this->data=data;
        this->prev=nullptr;
        this->next=nullptr;
    }
};
Node* ceateArray2LL(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* prev=head;//tracking back ptr/prev node ka ptr
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        temp->prev=prev;
        prev->next=temp;
        prev=temp;
    }
    return head;
}
int lengthOfDLL(Node* &head){
    int cnt=0;
    Node*temp=head;
    while(temp!=nullptr){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}
void traverseLL(Node *&head){
    Node*temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
bool searchInDLL(Node* &head,int val){
    Node*temp=head;
    while(temp!=nullptr){
        if(temp->data==val){
            return true;
        }
        temp=temp->next;
    }
    return false;
}
Node* deleteFromHead(Node*& head){
    if(head==nullptr || head->next==nullptr){
        //zero or one element case
        return nullptr;
    }
    // >1 element
    Node*temp=head;
    head=head->next;
    temp->prev=nullptr;
    temp->next=nullptr;
    delete temp;
    return head;
}
Node *deleteFromTail(Node *&head){
    if(head==nullptr || head->next==nullptr){
        //zero or one element case
        return nullptr;
    }
    // >1 element
    Node*temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    Node* prev=temp->prev;
    temp->prev=nullptr;
    prev->next=nullptr;
    delete temp;
    // temp->next->prev=nullptr;
    // temp->next=nullptr;
    // delete temp->next;
    return head;
}
Node* deleteWithK(Node* &head,int k){
    int len=lengthOfDLL(head);
    if(head==nullptr) return nullptr;
    if(head->next==nullptr && head->prev==nullptr){
        delete head;
        return nullptr;
    }
    if(k>len) return head;
    if(k==1) return deleteFromHead(head);
    if(k==len) return deleteFromTail(head);
    Node*temp=head;
    int cnt=0;
    while(temp!=nullptr){
        cnt++;
        if(cnt==k) {
            break;
        }
        temp=temp->next;
    }
        Node*prev=temp->prev;
        prev->next=temp;
        Node*front=temp->next;
        front->prev=temp;
        prev->next=front;
        front->prev=prev;
        temp->next=nullptr;
        temp->prev=nullptr;
        delete temp;
    return head;
}
// Node!=head
// void deleteNode(Node*&head){
//     Node*prev=head->prev;
//     Node*front=head->next;
//     if(front==nullptr){
//         prev
//     }
// }
// if we insert or delete b4 head ,head will change 
int main(){
vector<int>arr={2,4,6,8,10,12,14};
Node* head=ceateArray2LL(arr);
cout<<head->data<<endl;
traverseLL(head);
cout<<endl;
cout<<"length of dll is "<<lengthOfDLL(head)<<endl;
cout<<searchInDLL(head,7)<<endl;
head=deleteFromHead(head);
traverseLL(head);
cout<<endl;
head=deleteFromTail(head);
traverseLL(head);
cout<<endl;
head=deleteWithK(head,5);
traverseLL(head);
cout<<endl;


}