#include<iostream>
#include<vector>
#include<set>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cout<<"Enter The Size: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter The Array Elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    /*Problem: Move All Negative to End */

    /* Brute Force Approach:
    1.Create a Temporary array.
    2. 1st Traverse the original array and copy all non-negative elements to the temporary array.
    3. 2nd Traverse the original array and copy all negative elements to the temporary array.
    4. Copy the temporary array back to the original array.
    Time Complexity: O(n) - The array is traversed twice.
    Space Complexity: O(n) - A temporary array is used to store the elements.
    */

    vector<int> temp;

    // 1st Traverse
    for(int i=0;i<n;i++){
        if(arr[i]>=0)
        temp.push_back(arr[i]);
    }
    // 2nd Traverse
    for(int i = 0;i<n;i++){
        if(arr[i]<0)
        temp.push_back(arr[i]);
    }

    //copy the temporary array back to the original array
    arr = temp;

    //print the array after moving all negative elements to the end
    cout<<"Array after moving all negative elements to the end: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    /* Optimized Approach :
    1. Use two pointers left and right, where left points to the beginning of the array and right points to the end of the array.
    2. If the element at the beginning is negative, swap it with the element at the end and move both pointers towards the center.
    3. If the element at the beginning is non-negative, move the left pointer to the right.
    4. If the element at the end is negative, move the right pointer to the left.
    5. Continue until the two pointers meet.
    time complexity: O(n) - The array is traversed once.
    space complexity: O(1) - No additional space is used.
    */
   int left = 0, right = n - 1;
   while (left < right) {
         if (arr[left] < 0 && arr[right] >= 0) {
                swap(arr[left], arr[right]);
                left++;
                right--;
          } else if (arr[left] >= 0) {
                left++;
          } else {
                right--;
          }
     }
     //print the array after moving all negative elements to the end
    cout<<"Array after moving all negative elements to the end: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    /*Optimized Approach : Using Two-pointer approach:Second Variation move all negative in front and positive in the back
    Ex: Input: arr = [-1, 2, -3, 4, -5]
    Output: arr = [-1, -3, -5, 2, 4]

    1. One pointer (i) points to the first negative element.
    2. Another pointer (j) traverses the array.
    3. When a negative element is found, it is swapped with the element at index i, and i is incremented.

    Time Complexity: O(n) - The array is traversed once.
    Space Complexity: O(1) - No additional space is used.
    */
    int i = 0;
    for(int j = 0; j < n; j++){
        if(arr[j] < 0){
            swap(arr[i], arr[j]);
            i++;
        }
    }

    cout<<"Array after moving all negative elements to the end: ";
    for(int k = 0; k < n; k++){
        cout<<arr[k]<<" ";
    }
    cout<<endl;
}