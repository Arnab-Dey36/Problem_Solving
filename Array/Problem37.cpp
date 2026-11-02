#include<iostream>
#include<vector>
#include<set>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cout<<"Enter The Size first Array: ";
    cin>>n;

    vector<int> arr1(n);
    cout<<"Enter The Array Elements: ";
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }

    /*Problem: Merge Two Sorted Arrays */

    /*Approach: Two Pointers 
    1. Initialize two pointers, one for each array.Let the first pointer point to the first element of the first array and 
    the second pointer point to the first element of the second array.
    2. Compare the elements pointed by the two pointers. 
    3. If the element in the first array is smaller, add it to the merged array and move the first pointer forward.
    4. If the element in the second array is smaller, add it to the merged array and move the second pointer forward.
    5. Repeat steps 2 and 3 until one of the arrays is exhausted.
    6. Add any remaining elements from the non-exhausted array to the merged array.
    Time Complexity: O(m + n) - where m and n are the sizes of the two arrays.
    Space Complexity: O(m + n) - for storing the merged array.
    */
   //input for second array
   int m;
   cout<<"Enter The Size of Second Array: ";
    cin>>m;
    
     vector<int> arr2(m);
     cout<<"Enter The Second Array Elements: ";
     for(int i=0;i<m;i++){
          cin>>arr2[i];
     }
    
    //  vector<int> merged;
    //  int left = 0, right = 0;
    //  while(left < n && right < m){
    //       if(arr1[left] <= arr2[right]){
    //             merged.push_back(arr1[left]);
    //             left++;
    //       }
    //       else{
    //             merged.push_back(arr2[right]);
    //             right++;
    //       }
    //  }
    
    //  // Add remaining elements of arr1[] if any
    //  while(left < n){
    //       merged.push_back(arr1[left]);
    //       left++;
    //  }
    
    //  // Add remaining elements of arr2[] if any
    //  while(right < m){
    //       merged.push_back(arr2[right]);
    //       right++;
    //  }
    //  // Copy result back to arr[]
    //  arr1 = merged;

    //  // Print the merged array
    //  cout<<"Merged Array: ";
    //  for(int k = 0; k < arr1.size(); k++){
    //       cout<<arr1[k]<<" ";
    // }  




    /*
    Optimal Solution: Using Two Pointers

    1. Both arrays are already sorted.
    2. First pointer points to the last element of the first array.
    3. Second pointer points to the first element of the second array.
    4. Compare arr1[first] and arr2[second].
    5. If arr1[first] > arr2[second]:
        - Swap them.
        - Move first backward.
        - Move second forward.
    6. If arr1[first] <= arr2[second], break because
    all remaining elements are already in the correct array.
    7. Finally, sort both arrays.

    Time Complexity:
    O((n + m) log(n + m)) - The arrays are sorted after merging

    Space Complexity:
    O(1) auxiliary space
*/
   int left = n - 1, right = 0;
   while(left >= 0 && right < m){
        if(arr1[left] > arr2[right]){
            swap(arr1[left], arr2[right]);
            left--;
            right++;
        }
        else{
            break;
        }
   }
   // Sort both arrays to get the final sorted arrays
   sort(arr1.begin(), arr1.end());
   sort(arr2.begin(), arr2.end());
   //copy the elements of second array to first array
   for(int k = 0; k < m; k++){
        arr1.push_back(arr2[k]);
   }
  
    //print the merged array
    cout<<"Merged Array: ";
    for(int k = 0; k < n; k++){
          cout<<arr1[k]<<" ";
    }
    for(int k = 0; k < m; k++){
          cout<<arr2[k]<<" ";
    }
    cout<<endl;

}