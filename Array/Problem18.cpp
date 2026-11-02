#include<iostream>
using namespace std;
int main(){
    int n,k;
    cout<<"Enter Size: ";
    cin>>n;

    int arr[100];
    cout<<"Enter The Array Elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Enter K: ";
    cin>>k;

    /* Problem: Longest Subarray with sum K
    Ex: arr[] = {1,2,3,1,1,1,1,4,2,3}  & k = 3 output: length=3
    task is to find the length of the longest subarray where the sum of its elements is equal to the given value k. 
    If there is no subarray with sum equal to k, return 0.
    */

    /*Brute Froce: Same as Problem-5
    1. Find all Possible SubArray. Now Question is How to find ALl Possible SubArray? --> Follow Problem-5 brute force example
    here, i=st & j=end
    
        Time Complexity = O(N^2) & Space Complexity = O(1)
    */
    int maxSum = INT_MIN,length=0;
    for(int i=0;i<n;i++){
        int currSum = 0;
        for(int j=i;j<n;j++){
            currSum += arr[j];
            if(currSum == k)
            length = max(length,j-i+1);
        }
    }
    cout<<length;
}