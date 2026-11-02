#include<iostream>
using namespace std;
int main(){
    int n,target;
    cout<<"Enter Size: ";
    cin>>n;

    int arr[100];
    cout<<"Enter The Array Elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    /* Problem: Find the numbers that appears once and other number twice
                Ex: arr[] = {1,1,2,3,3,4,4} output-2
    */

    /*Brute Force:
    1. Pick one element first, then check the whole array, this number 
    present more then one times, if present then count++
    2. After this, check again if count = 1 then this number appears once
        Time Complexity = O(N^2) & Space Complexity = O(1) 
    */
    for(int i=0;i<n;i++){
        int nums= arr[i]; //pick i-th element first and store it in nums
        int count = 0;
        for(int j=0;j<n;j++){
            if(arr[j] == nums)
            count++;
        }
        if(count == 1){
            cout<<nums;
        }
    }

    /*Optimal Solution:
    1. Calculate the XOR of all Array Element
        (1^1)^2^(3^3)^(4^4) = 0^2^0^0 = 2
        T.C => O(N) & S.C = O(1)
    */
    int ans=0;
    for(int i=0;i<n;i++){
        ans ^= arr[i];
    }
    cout<<ans;

}