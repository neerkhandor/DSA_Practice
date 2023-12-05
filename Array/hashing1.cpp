// lot of time it is asked what is freq of a no
// 10 to the power 8 takes 1sec
// pre store something and fetching
// i will create other array and call it as hash/freq array and init to 0
// i will do some precomputation i will traverse th einput array and it will remember in the created array
// at hash[1] i get count of 1
// single precomputation
// go to that index and increase it value by i
// here we have the size of hash array equal to maximum element in the array
// inside main the maxm size of int array i can store is 10^6
// if i cross this limit then it will give segmentation fault because i will not able to allocate this much memory
// outside main the maxm size of int array i can store is 10^7
// for boolean array inside main maxm size of bool array i can store is 10^7
// for boolean array inside main maxm size of bool array i can store is 10^8
// if you declare anything globally then it is automatically initialized to 0


#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
// int arr[1e7];
int main(){
    int arr[]={1,2,4,5,7,8,2,1,1,1,1,3,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int hash[10]={0};//this size depends what all nos can be there
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }
    for(int i=0;i<10;i++){
        cout<<hash[i]<<" ";
    }
    cout<<endl;
    // character hashing
    // character frequency 
    string str="hello world";
    int charArr[26]={0};
    for(int i=0;i<str.length();i++){
        // char-'a' will give me the index
        // this will make the asci codes to normal nos
        // but if i have considered all characters and created an array of size 256 then
        // i might just have done charArr[str[i]]++;
        // but since we didnt want characters other than lowercase therefore we created array of size 26
        // character hashing doesnt have any problem because they are at max 256 and hashing 256 elements is not a problem
        // so if we just want lowercase then do charArr[str[i]-'a']
        // if we want uppercase then do charArr[str[i]-'A']
        // if we want all character then simply hash the character
        // if i say s[i] then it will autoconvert to its ascii
        // so in hash[s[i]] s[i] is an index so it has to be number so it will autoconvert the character to number but that no will be ascii value
        
        charArr[str[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        cout<<charArr[i]<<" ";
    }
    cout<<endl;
    // what for elements greeater than 10^7 stl comes
    // one is map and other is unordered_map
    // mao <int ,  int>
    //     key    value
    //     number  freq
    // here you are jsut storing the elements that are required
    // mpp[arr[i]]++
    int a[10]={1,2,2,2,3,3,3,3,3,3};
    int n1=sizeof(a)/sizeof(a[0]);
    // depending on the size of the number you can decide your key's no
    // map store all the elements in sorted order
    map<int,int>mpp;
    for(int i=0;i<n1;i++){
        mpp[a[i]]++;
    }
   // int s=mpp.size();
    // for(int i=0;i<s;i++){
    //     cout<<mpp[i]<<" ";
    // }
    for(auto it:mpp){
        cout<<it.first<<" -> "<<it.second;
        cout<<endl;
    }
    cout<<endl;


    // depending on what you want to hash becomes your key
    // storing and fetching in map takes log(n) in all cases
    // here n is no of elements in an array
    // but there is something unordered_map
    // map<char,int> charmpp;
    unordered_map<char,int> charmpp;//it doesnt store in an order
    // avg and best case is O(1)
    // in worst case it is O(n)
    // worst case very rarely happens so it is preffered to use unordered_map
    // in some case if tle comes than only in such cases we have to shift to map
    // now why this worst case happens -> because of internal collision
    // chaining can be done using division method
    // we use %10 approach where we hash it according to %10 value
    // what if after %10 all no came at same hash index in this case worst case comes
    // now here no need to convert into integer because map will actually store characters
    // key can be anything an int,char,boolean,pair<int,int> in map
    // but in unordered_map we can only have individual data type we cannot have mpp<pair<int,int>,int>
    

    string s="hello this is neer i m learning from striver";
    int len=s.length();
    for(int i=0;i<len;i++){
        charmpp[s[i]]++;
    }
    for(auto it:charmpp){
        cout<<it.first<<" -> "<<it.second;
        cout<<endl;
    }
    cout<<endl;
}

