// pushes maximum element to the last does adjacent swapping
#include<iostream>
using namespace std;

int main(){
    int arr[]={1,2,4,5,6,7,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    // after every step last element is it correct place
    // for the first time we went from 0 to n-1   n
    // next time we went from 0 to n-2;   n-1
    // then further we went from 0 to n-3;   n-2
    // worst case and average tc->O(n2)
    // best case ->O(n)
    bool flag=false;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag=true;
            }
        }
        if(flag==false){
            break;
        }
        cout<<"broke the loop";
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}