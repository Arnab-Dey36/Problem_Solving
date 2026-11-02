#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main(){
    int n,target;
    cout<<"Enter The Size of Array: ";
    cin>>n;

    vector<int>arr(n);
    cout<<"Enter The Vector Elements: ";
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
   

    /*Problem: Single Element in a Sorted Array
    Description:You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
    Return the single element that appears only once.*/

    /*Approach: Binary Search
    1. Find the mid element of the array.
    2. If the mid element is equal to the element before it, check if the single element is in the left half or right half.
    3. If the mid element is equal to the element after it, check if the single element is in the left half or right half.
    4. Continue the process until the single element is found.
    Time Complexity: O(log n) and Space Complexity: O(1)
    */
    int st =0,end = n-1;
    while(st<end){
        int mid = st+(end-st)/2;

        if(mid%2 == 1) mid--; //make mid even

        if(arr[mid] == arr[mid+1]){
            st = mid+2;
        }
        else{
            end = mid;
        }
    }
    cout<<"The single element is: "<<arr[st]<<endl;

}