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
    cout<<"Enter The Target Element: ";
    cin>>target;


    /*Problem: Search Element in Rotated Sorted Array II
    Note: The array may contains duplicate elements.
    */

    /*Approach: Binary Search
    1. Find the mid element of the array.
    2. If the mid element is equal to the target element, return true.
    3. If the left half of the array is sorted, check if the target element lies in the left half. If it does, search in the left half, otherwise search in the right half.
    4. If the right half of the array is sorted, check if the target element lies in the right half. If it does, search in the right half, otherwise search in the left half.
    5. For duplicate elements, if the mid element is equal to the left and right element, we can skip the duplicate elements by moving the left or right pointer accordingly.

    6. Continue the process until the target is found or the search space is exhausted.
    7. If the target is found, return true. Otherwise, return false.
    Time Complexity: O(log n) in average case, O(n) in worst case due to duplicates.
    */
   int st =0,end = n-1;
   while(st<=end){
        int mid = st+(end-st)/2;

        if(arr[mid] == target){
            cout<<true;
            return 0;
        }

        //For Duplicate
        if(arr[mid] == arr[st] && arr[mid] == arr[end]){
            st++,end--;
            continue;
        }
        //Left half sorted
        else if(arr[st]<=arr[mid]){
            if(arr[st] <= target && target <= arr[mid])
                end = mid-1;
            else
                st = mid+1;
        }
        //right half sorted
        else{
            if(arr[mid]<=target && target<=arr[end])
                st = mid+1;
            else 
                end = mid-1;
        }
   }
   cout<<false;
   return 0;
}