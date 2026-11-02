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


    /*Problem:  Find Peak Element*/

    /*Brute Force Approach:Linear Search*/
    for(int i=0;i<n;i++){
        if((i == 0 || arr[i]>=arr[i-1]) && (i == n-1 || arr[i]>=arr[i+1]))
        {
            cout<<arr[i];
            break;
        }
    }
    return 0;

    /*Approach: Binary Search
    1.Initialize low and high pointers.
    2.Find the middle element.
    3.Check if the middle element is a peak.Condition for peak element is arr[mid] >= arr[mid-1] and arr[mid] >= arr[mid+1].
    4.If the middle element is a peak, return it means mid.
    5.If the middle element is not a peak, check if the middle element is greater than its left neighbor. If it is, then the peak element lies on the right side of mid. So, set low = mid + 1.
    6.If the middle element is not a peak and it is greater than its right neighbor, then the peak element lies on the left side of mid. So, set high = mid - 1.
    7.Repeat until a peak is found.
    8. The time complexity of this approach is O(log n) and the space complexity is O(1).
    9.if(n==1) return arr[0];  //if only one element is present in the array then return that element as peak element
    10.if(arr[0]>arr[1]) return 1;  //if the first element is greater than the second element then return the first element as peak element
    11.if(arr[n-1]>arr[n-2]) return n-1;  //if the last element is greater than the second last element then return the last element as peak element
    */

    //if one element is present in the array then return that element as peak element
    if(n==1){
        cout<<arr[0];
        return 0;
    }
    int st = 0,end = n-1;
    while(st<=end){
        int mid = st+(end-st)/2;


        if(arr[mid]>=arr[mid-1] && arr[mid]>=arr[mid]+1)
        {
            cout<<arr[mid];
            break;
        }

        else if(arr[mid]>arr[mid+1]){
            end = mid-1;
        }
        else st = mid+1;
    }
}