// we select the minimums
// we look the entire array find minm and place it to the first location and 
// swap the other element to the minm wala place
// after 1st step 1st element is sorted
// we dont have to sort last element because it will be automatically 
// to its correct position
// get the minm and sort it
// swap first time happens from 0 to n-1 in this range i have to find minm
// swap second time happens from 1 to n-1
// i will go till n-1 because i will not consider last element 
// best worst and avg case is O(N^2)
#include <iostream>

using namespace std;

int main()
{
    int arr[]={6,3,68,23,35,88,54,24,78};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n-1;i++){
        int mini=arr[i];
        for(int j=i;j<n;j++){
            if(arr[mini]>arr[j]){
                mini=j;
            }
        }
        swap(arr[mini],arr[i]);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
cout<<endl;

    return 0;
}