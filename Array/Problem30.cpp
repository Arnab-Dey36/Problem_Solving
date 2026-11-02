
#include <iostream>
using namespace std;
int main()
{
    int n,target;
    cout << "Enter The Size: ";
    cin >> n;
   
    int arr[100];
    cout << "Enter The Array Elements: ";
    for (int i = 0; i < n; i++)
    {
       cin>>arr[i];
    }
    cout << "Enter The Target: ";
    cin >> target;



/*Problem: Count Subarray sum Equals K*/

    /*Brute Force Approach:
    1. Generate all possible subarrays.
    2. Calculate the sum of each subarray.
    3. Count the number of subarrays whose sum equals K.
    Time Complexity: O(n^3), Space Complexity: O(1)
    */
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum += arr[k];
            }
            if(sum == target)
            count++;
        }
    }
    cout<<count;

    /*Better Approach:
    Time Complexity: O(n^2), Space Complexity: O(1)
    */
   int count1 = 0;
   for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum += arr[j];
            if(sum == target)
            count1++;
        }
    }
    cout<<count1;

}