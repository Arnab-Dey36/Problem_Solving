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

    /*Poblem: Binary Search*/
    /*Approach:
    1. The array must be sorted.
    2. Calculate the mid element and Compare the target value with the mid element of the array.
    3. If the target is equal to the middle element, return the index.
    4. If the target is less than the middle element, search in the left half.And move the right pointer to mid-1.
    5. If the target is greater than the middle element, search in the right half.And move the left pointer to mid+1.
    6. Repeat steps 2-5 until the target is found or the left pointer exceeds the right pointer.
    Time Complexity: O(log n) & Space Complexity: O(1)
    */

    sort(arr.begin(),arr.end());
    
    int st = 0,end= n-1;
    while(st<=end){

        int mid = st + (end-st)/2;

        if(arr[mid] == target){
            cout<<"index: "<<mid;
            break;
        }

        else if(arr[mid]>target) end = mid-1;

        else st = mid+1;
    }
}