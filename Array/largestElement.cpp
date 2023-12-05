// whenever unique word comes think of set
#include<iostream>
using namespace std;
int main(){
    int arr[]={3,5,7,1,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int largest=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }
    cout<<"Largest Element in the array is "<<largest<<endl;
}