#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool CanWePlace(vector<int>&arr,int dist,int cows){

    //for first cow take first place
    int countCows = 1, lastPosition = arr[0];

    for(int i = 1;i<arr.size();i++){
        if(arr[i] - lastPosition >= dist){
            countCows++;
            lastPosition = arr[i];
        }
        if(countCows>=cows) return true;
    }
    return false;
}

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

    /*Problem: Aggressive Cows*/

    /** Algorithm:
     * 1. First, sort the array of stall positions.
     * 2. Initialize start = 1 (minimum distance) and end = arr[n-1] - arr[0] (maximum distance).
     * 3. While start <= end:
     *    - Calculate mid = start + (end - start) / 2.
     *    - Check if it is possible to place k cows with at least mid distance.
     *    - If a distance is possible to set cows, store mid as the answer and try a bigger distance: st = mid + 1.
     *    - Otherwise, If a distance is not possible, try a smaller distance: end = mid - 1.
     * 4. Return the maximum distance found.
     * Time Complexity: O(nlogn) and Space Complexity: O(1).
    */
    
    sort(arr.begin(),arr.end());
    int st = 1; // because two cows ke beach ka distance humesa 1 rahegai.
    int end = arr[n-1] - arr [0]; // because worst case mein first cow ko first stall mein aur second cow ko last 
    //stall mein rakha jaega toh uske beach distance = arr[n-1]-arr[0] hoga.
    int ans = -1;

    while (st<=end)
    {
        int mid = st+(end-st)/2;

        if(CanWePlace(arr,mid,k) == true){
            ans = mid;
            st = mid+1;
        }
        else end = mid-1;
    }
    
    cout<<ans;
    
}