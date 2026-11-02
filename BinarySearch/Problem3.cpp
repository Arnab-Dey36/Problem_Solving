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

    /*Problem: Ceil in Sorted Array
    Ceil: The smallest element in the array that is greater than or equal to the target. OR,
                i.e,  The smallest element in the array >= target 
    */

    /*Approach: Binary Search
    1. Initialize low = 0 and high = n - 1.
    2. While low <= high:
        a. Calculate mid = (low + high) / 2.
        b. If arr[mid] >= target, update res = mid and high = mid - 1.
        c. Else, update low = mid + 1.
    3. Return res.
    If no such element exists, return -1. thats why res is initialized to -1.
    time complexity: O(log n) And space complexity: O(1).
    */
   sort(arr.begin(),arr.end());
   int st = 0,end = n-1,res = -1;

   while(st<=end){
    int mid = st + (end - st)/2;
    if(arr[mid] >= target){
        // res = mid;
        res = arr[mid];
        end = mid-1;
    }
    else st = mid+1;
   }
  //cout<<"Ceil Index is: "<<res;
   cout<<"Ceil value is: "<<res<<endl;




   /*Problem: Floor in Sorted Array
    Floor: The largest element in the array that is less than or equal to the target. OR,
                i.e,  The largest element in the array <= target 
    */
   /*Approach: Binary Search
    1. Initialize low = 0 and high = n - 1.
    2. While low <= high:
        a. Calculate mid = (low + high) / 2.
        b. If arr[mid] <= target, update res = mid and low = mid + 1.
        c. Else, update high = mid - 1.
    3. Return res.
    If no such element exists, return -1. thats why res is initialized to -1.
    time complexity: O(log n) And space complexity: O(1).
    */
   int low = 0,high = n-1,ans = -1;
   while(low<=high){
    int mid = low + (high - low)/2;

    if(arr[mid] <= target){
        ans = arr[mid];
        low = mid+1;
    }
    else high = mid-1;
   }

   cout<<"Floor value is: "<<ans;
}