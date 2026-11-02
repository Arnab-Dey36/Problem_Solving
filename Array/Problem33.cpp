#include<iostream>
#include<vector>
#include<set>
#include <algorithm>
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

    /*Problem: Duplicates in Limited Range Array
    Explain:Given an array arr[] of size n, containing elements from the range 1 to n, 
    and each element appears at most twice, return an array of all the integers that appears twice.*/


    /*Brute Force: Using a nested loop
    1. Use a nested loop to compare each element with every other element.
    2. If two elements are equal, add it to the result.
    3. And break the inner loop to avoid adding the same element multiple times.

    Time Complexity: O(n^2) - The nested loops result in a quadratic time complexity.
    Space Complexity: O(n) - The space used to store the result array.
    */

    vector<int> result;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                
                result.push_back(arr[i]);
                break; // Break the inner loop to avoid adding the same element multiple times
            }
        }
    }

    for(int i : result){
        cout<<i<<" ";
    }
    cout<<endl;



    /* Better Approach: 
    1. Sort array
    2. i = 1 se start karo
    3. Agar arr[i] == arr[i-1], duplicate mila
    4. result mein add karo

    Time Complexity: O(nlogn) - The sorting step takes O(nlogn) time, and the subsequent loop takes O(n) time.
    Space Complexity: O(n) - The space used to store the result array.
    */
    vector<int> ans;
    // Sort the array
    sort(arr, arr + n);

    for (int i = 1; i < n; i++) {

        if (arr[i] == arr[i - 1]) {
            ans.push_back(arr[i]);
        }
    }
    // Print the ans
    cout << "The Duplicate Elements are: ";
    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;



    /*Optimal Approach: Using a set
    1. start from loop j = 1 to n and i = 0
    2. Agar arr[j] == arr[i], duplicate mila and uss duplicate ko usi Array index pe store karo arr[i] = arr[j]
    3. i++ karo
    Time Complexity: O(n) - The loop runs in linear time.
    Space Complexity: O(1) - No extra space is used.
    */

    int i = 0;
    for(int j = 1;j<n;j++){
        if(arr[j] == arr[i])
        {
            arr[i] = arr[j];
            i++;
        }
    }
    for(int k = 0;k<i;k++){
        cout<<arr[k]<<" ";
    }

}