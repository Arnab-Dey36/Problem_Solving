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

    /*Problem: Implement Lower Bound

    * The lower bound of a number is defined as the smallest index in the sorted array where 
    * the element is greater than or equal to the given number.i.e, arr[mid] >= target.
    * If all the elements in the given array are smaller than the target, 
    * the lower bound will be the length of the array. 
    */

    /*Binary Search Implementation for Lower Bound And Upper Bound:
    1. Initialize the left pointer to 0 and the right pointer to n-1.
    2. While the left pointer is less than or equal to the right pointer:
        a. Calculate the middle index as (left + right) / 2.
        b. If the element at the middle index is greater than or equal to the target, 
        update the result and move the right pointer to mid - 1.
        c. Otherwise, move the left pointer to mid + 1.
    3. Return the result.
    4. Initialize the result to n, which represents the case where all elements are smaller than the target.
    Time Complexity: O(log n) & Space Complexity: O(1)

    NOTE: For Upper Bound, the condition in step 2b should be changed to arr[mid] > target.
    Remaining steps will be the same as lower bound.
    */
   
    int ans = n;
    int st =0,end=n-1;
    while (st<=end)
    {
        int mid = st + (end-st)/2;

        // Lower Bound Condition: arr[mid] >= target
        if(arr[mid] >= target){
            ans = mid;
            end = mid-1;
        }

        // Upper Bound Condition: arr[mid] > target
        // if(arr[mid] > target){
        //     ans = mid;
        //     end = mid-1;
        // }
       
        else st = mid + 1;
    }
    cout<<"Lower Bound Index: "<<ans;
    // cout<<"Upper Bound Index: "<<ans;
}