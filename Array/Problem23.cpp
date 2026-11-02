#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter The Size: ";
    cin>>n;

    int arr[100];
    cout<<"Enter The Array Elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }

    /*Problem: Array Leaders(GFG)
    Definition of leader: Everything is the right should be smaller than the leader.
    */

    /*Brute Force Approach:
    1. Loop through the array from 0 to n.
    2. Consider the current element as a leader.And set a flag variable isLeader = true.
    3. Loop through the array from i+1 to n and check if any element is greater than the current element.
    4. If any element is greater than the current element then set isLeader = false
    5. If isLeader is still true, then the current element is a leader.

    6. Time Complexity: O(n^2) and Space Complexity: O(n)
    */
    vector<int>ans;
    for(int i=0;i<n;i++){
        int isLeader = true;
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                isLeader = false;
                break;
            }
        }

        if(isLeader == true){
            ans.push_back(arr[i]);
        }
    }

    for(int i : ans){
        cout<<i<<" ";
    }

    /*Optimal Approach:
    1. Loop through the array from n-1 to 0.
    2. consider a maxi_Element = INT_MIN to store the maximum element.
    3. If the current element is greater than or equal to the maximum element, it is a leader.
    4. Update the maximum element with the current element.
    5. Store the leader in a vector.

    6. Time Complexity: O(n) and Space Complexity: O(1)
    */
   vector<int>ans2;
    int maxElement = INT_MIN;
    for(int i=n-1;i>=0;i--){
        if(arr[i]>=maxElement){
            ans2.push_back(arr[i]);
        }
        maxElement = max(maxElement,arr[i]);
    }

    // Reverse the vector to get the leaders in the original order
    // reverse(ans2.begin(), ans2.end());

    for(int i : ans2){
        cout<<i<<" ";
    }

}