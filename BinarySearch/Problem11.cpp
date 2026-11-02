#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n,k;

    cout<<"Enter The Value of n: ";
    cin>>n;

    vector<int>arr(n);
    cout<<"Enter Elements: ";
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter The Value of K: ";
    cin>>k;

    /*Problem: Kth Missing Positive Number*/

    /** Algorithm:
     * 1. Initialize start = 0 and end = n -1.
     * 2. While start <= end:
     *    - Calculate mid = start + (end - start) / 2.
     *    - Calculate missing numbers before arr[mid] using missing = arr[mid] - (mid + 1).
     *    - If missing < k, move right: start = mid + 1.
     *    - Otherwise, move left: end = mid - 1.
     * 3. Return start + k, which gives the k-th missing positive number.
    */
    
    int st = 0,end = n-1;
    while (st<=end)
    {
        int mid = st+(end-st)/2;

        int Missing = arr[mid] - (mid+1);
        if(Missing<k)  st = mid+1;

        else end = mid-1;
    }
    
    cout<< st +k;
    
}