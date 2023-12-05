#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(int data,Node*next){
        this->data=data;
        this->next=next;
    }
    Node(int data){
        this->data=data;
        this->next=nullptr;
    }

};
// we have to return head of the ll so we will have return type of Node*
// we dont want to update head ptr therefore we have a mover ptr pointing to head which will help us in traversal
// we are creating ll so every time we have do Node* newElement = new Node(data)
Node* convertArray2LL(vector<int>& arr){
    Node*head=new Node(arr[0]);
    Node *mover=head;
    for(int i=1;i<arr.size();i++){
        Node*temp=new Node(arr[i]);
        mover->next=temp;
        mover=mover->next;
        // mover=temp;
    }
    return head;
}
// never ever temper the head
// we will take temp variable
void traverseLL(Node *&head){
    Node*temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int lengthOfLL(Node *&head){
    int cnt=0;
    Node*temp=head;
    while(temp!=nullptr){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}
bool searchInLL(Node* &head,int val){
    Node*temp=head;
    while(temp!=nullptr){
        if(temp->data==val){
            return true;
        }
        temp=temp->next;
    }
    return false;
}
Node* deleteHead(Node*&head){
    if(head==NULL) return head;
    Node*temp=head;
    head=head->next;
    temp->next=NULL;
    delete temp;
    return head;
}
Node* deleteTail(Node *&head){
    // i need to step before the last element
    // for ll with one element it will be head and tail itself so i simply delete them
    if(head == nullptr || head->next == nullptr){
        return nullptr;
    }
    // now from here we will atleast have 2 elements
    Node*temp=head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
    return head;
}
Node* deleteK(Node* &head,int k){
    int len=lengthOfLL(head);
    if(head==nullptr) return head;
    if(k>len) return head;
    if(k==1) return deleteHead(head);
    if(k==len) return deleteTail(head);
    Node*temp=head;
    Node*prev=nullptr;
    int cnt=0;
    while(temp!=nullptr){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }    
    return head;
}
Node *deleteValue(Node* &head,int element){
    if(head==nullptr) return nullptr;
    if(head->data==element){
        Node*temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    Node*temp=head;
    Node*prev=nullptr;
    while(temp!=nullptr){
        if(temp->data == element){
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    // in case that element is not found then head itself will be returned
    return head;
}
Node *insertAtHead(Node*head,int data){
    // i will return temp as it will be my new head
    if(head==nullptr){
        // cout<<"null head";
        Node* newNode=new Node(data);
        return newNode;
    }
    Node* newNode=new Node(data);
    if(newNode->next)
    {
        newNode->next=head;
    }
    return newNode;
    
    // Node *temp=new Node(val,head); val will be taken from parameter and next pointing will be head
    // return temp;
}
Node* insertAtTail(Node* &head,int data){
    if(head==nullptr){
        return new Node(data);
    }
    Node*temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    Node*newNode=new Node(data);
    temp->next=newNode;
    return head;
}
// insert at k
Node* insertAtk(Node* &head,int data,int k){
    int len=lengthOfLL(head);
    // if(head==nullptr) return new Node(data);
    // if(k==1) return insertAtHead(head,data);
    // if(k>=len) return insertAtTail(head,data);
    if(head==nullptr){
        if(k==1){
            return new Node(data);
        }
        else{
            return head;
        }
    }
    if(k==1){
        return new Node(data,head);
    }
    Node*temp=head;
    int cnt=0;
    while(temp!=nullptr){
        cnt++;
        if(cnt== (k-1)){
            Node* newNode=new Node(data);
            newNode->next=temp->next;
            temp->next=newNode;
            break;
        }
        temp=temp->next;
    }
    return head;
}
// incase element is not present than we can have a flag to check whether that element is there or not
// if it is not present than we can give some cout statement
Node* insertBeforeValue(Node* &head,int data,int element){
    if(head==nullptr){
        return nullptr;
    }
    if(head->data==element){
        return new Node(data,head);
    }
    int flag=0;
    Node*temp=head;

    while(temp->next!=nullptr){
        if(temp->next->data == element){
            Node* newNode=new Node(data);
            newNode->next=temp->next;
            temp->next=newNode;
            flag=1;
            break;
        }
        temp=temp->next;
    }
    if(flag==0){
        cout<<element<<" is not present in the ll"<<endl;
    }
    return head;
}
int main(){

    vector<int>arr={12,16,20,24,28,32,36,40,44};
    Node* head=convertArray2LL(arr);
    cout<<head->data<<endl;
    traverseLL(head);
    cout<<endl;
    int len=lengthOfLL(head);
    cout<<"Length of ll is "<<len<<endl;
    bool search=searchInLL(head,16);
    if(search){
        cout<<"Element present"<<endl;
    }
    else{
        cout<<"Element Absent"<<endl;
    }
    // i want new head so i will be replacing existing head with
    head=deleteHead(head);
    traverseLL(head);
    cout<<endl;
    
    head=deleteTail(head);// head of new ll
    traverseLL(head);
    cout<<endl;
    head=deleteK(head,8);
    traverseLL(head);
    cout<<endl;
    head=deleteValue(head,16);
    traverseLL(head);
    cout<<endl;
    //Node*head1=nullptr;
    // head1=insertAtHead(head1,4);
    // traverseLL(head1);
    // cout<<endl;
    // head1=insertAtTail(head1,10);
    // traverseLL(head1);
    head=insertAtTail(head,100);
    traverseLL(head);
    cout<<endl;
    head=insertAtk(head,200,9);
    traverseLL(head);
    cout<<endl;
    head=insertBeforeValue(head,300,20);
    traverseLL(head);
    cout<<endl;


}