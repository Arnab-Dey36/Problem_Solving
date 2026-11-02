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

    /*Problem:  Search Element in Rotated Sorted Array - I*/

    /*Approach: Binary Search
    1. Find the middle element.
    2. If the middle element is the target, return its index.
    3. If the left half is sorted and the target is in it, search the left half.
    4. Otherwise, search the right half.
    
    How to Check if the left half is sorted?
    If the middle element is greater than or equal to the first element, then the left half is sorted.And if target lies between the first element and the middle element, then search the left half means end = mid-1 aur if not lies in the left half then search the right half means st = mid+1.

    How to Check if the right half is sorted?
   If the middle element is less than or equal to the first element, then the right half is sorted.And if target lies between the middle element and the last element, then search the right half means st = mid+1 aur if not lies in the right half then search the left half means end = mid-1.

    Time complexity: O(log n) And space complexity: O(1).
    */

    int st = 0,end = n-1;

    while (st<=end)
    {
        int mid = st+(end-st)/2;

        if(arr[mid] == target){
            cout<<mid;
            break;
        }
        //check left half sorted
        else if(arr[mid]>=arr[st]){
            //Check target lie in left half or not
            if(arr[st]<=target && target<=arr[mid]){
                end = mid-1;
            }
            else st = mid+1;
        }
        //check Right half sorted
        else{
            //Check target lie in RIght half or not
            if(arr[mid]<=target && target<=arr[end]){
                st = mid + 1;
            }
            else end = mid-1;
        }
    }
    return 0;
}