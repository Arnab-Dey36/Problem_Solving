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

    /*Problem:  First and Last Occurrences in Array*/
    
    /*Approach: Binary Search
    Find the first occurrence of the target element.
    Steps:
    1. Initialize low = 0 and high = n - 1 and first = -1.
    2. While low <= high:
        a. Calculate mid = (low + high) / 2.
        b. If arr[mid] == target, update res = mid and check leftside of the array if there is any other occurrence of the target element. So, update high = mid - 1.
        c. Else if arr[mid] < target, update low = mid + 1.
        d. Else, update high = mid - 1.
    3. Return res.
    If no such element exists, return -1. thats why res is initialized to -1.
    Time complexity: O(log n) And space complexity: O(1).
    */
    
    int st = 0,end = n-1;
    int first = -1;
    while(st<=end){
        int mid = st+(end-st)/2;

        if(arr[mid] == target){
            first = mid;
            end = mid-1;
        }
        else if(arr[mid]<target)
            st = mid+1;
        else end = mid-1;
    }

    cout<<"First Occurrence is: "<<first<<endl;

    /*
     Find the last occurrence of the target element.
    Steps:
    1. Initialize low = 0 and high = n - 1 and last = -1.
    2. While low <= high:
        a. Calculate mid = (low + high) / 2.
        b. If arr[mid] == target, update res = mid and check rightside of the array if there is any other occurrence of the target element. So, update low = mid + 1.
        c. Else if arr[mid] < target, update low = mid + 1.
        d. Else, update high = mid - 1.
    3. Return res.
    If no such element exists, return -1. thats why res is initialized to -1.
    Time complexity: O(log n) And space complexity: O(1).*/

    int low = 0,high = n-1;
    int last= -1;
    while (low<=high)
    {
        int mid = low+(high-low)/2;

        if(arr[mid] == target){
            last = mid;
            low = mid+1;
        }
        else if(arr[mid]<target)
            low = mid+1;
        
        else high = mid-1;
    }
    cout<<"Last Occurrence is: "<<last<<endl;

    
}