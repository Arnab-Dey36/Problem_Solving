#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,k;
    cout<<"Enter Size: ";
    cin>>n;
    
    cout<<"Enter K: ";
    cin>>k;

    int arr[100];
    cout<<"Enter The Array Elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }



    /*Brute Force using Linear Search
    1. start first loop from 0 to n-1
    2. start 2nd loop from i+1 to n
    3. check sum of two element(arr[i]+arr[j]) == k or not if equal to k then then return those two element.
    4. here we see first loop n-1 tak ja raha because agar 'i' last tak (n) taka jata to uske bad koi element nahi hai add karne ke liya that's why n-1 tak ja raha hai.

    5. Time Complexity = O(N^2) & Space Complexity = O(1)
    */
    vector<int>ans1;
    for(int i = 0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j] == k)
           {
             ans1.push_back(arr[i]);
            ans1.push_back(arr[j]);
            break;
           }
        }
    }

    //print
    for(int val : ans1){
        cout<<val<<" ";
    }


    /*Optimal Approche using Two pointer Approche:
    1. sort the array first because we are using two pointer approch and two pointer approch only works on sorted array.
    2. take two pointer st=0 & end=n-1
    3. check sum of two element(arr[st]+arr[end]) == k or not if equal to k then return those two element.
    4. if sum < k then st++ else end--
    5. Time Complexity = O(NlogN) & Space Complexity = O(1)
    6. Note: This approch only works on sorted array.
    */
   vector<int>ans;
   int st=0,end=n-1;
   while(st<end){
        if(arr[st]+arr[end] == k){
            ans.push_back(arr[st]);
            ans.push_back(arr[end]);
            break;
        }
        else if(arr[st]+arr[end] < k){
            st++;
        }
        else{
            end--;
        }   
   }
    //print
    for(int val : ans){
        cout<<val<<" ";
    }
}