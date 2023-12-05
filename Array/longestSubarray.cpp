#include<iostream>
using namespace std;

int main(){
    int a[]={3,5,1,2,4};
    int n=5;
    int k=9;
    int len=0;
     for (int i = 0; i < n; i++) { // starting index
        for (int j = i; j < n; j++) { // ending index
            // add all the elements of
            // subarray = a[i...j]:
            long long s = 0;
            for (int K = i; K <= j; K++) {
                s += a[K];
                if (s == k)
                len = max(len, j - i + 1);
            }

            
        }
    }
    cout<<len<<endl;

}