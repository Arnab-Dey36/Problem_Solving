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
    /*Problem: Next Permutation */

    /*Brute Force Approach:
    1. Generate all the permutations of the given array and store them in a vector.
    2. Sort the vector of permutations in ascending order.
    3. Find the index of the given array in the sorted vector of permutations.
    4. If the index is not the last index, return the permutation at the next
    index. Otherwise, return the first permutation in the sorted vector.
    5. Time Complexity: O(n! * n) + O(n log n) and Space complexity: O(n! * n)
    */

    /*Better Approach: using STL next_permutation function to find the next permutation of the given array.*/
    

    /*
    Optimized Approach:
    1. Find the pivot element,condition for pivot is arr[i] < arr[i+1].
    2. Find the rightmost element which is greater than the pivot element,let's say arr[j].
    3. Swap the rightmost element with the pivot element,Say we swap arr[i] and arr[j].
    4. Reverse the pivot+1 to end of the array(n-1).
    5. Time Complexity: O(n) and Space Complexity: O(1)
    */
    
    //find pivot element
    int pivot=-1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            pivot = i;
            break;
        }
    }
    //if privot not exit
    if(pivot == -1){
        int i=0,j=n-1;
        while(i<=j){
            swap(arr[i],arr[j]);
            i++,j--;
        }
        return 0;
    }
    //find rightmost element greater than pivot
    for(int i=n-1;i>pivot;i--){
        if(arr[i]>arr[pivot]){
            swap(arr[i],arr[pivot]);
            break;
        }
    }
    //reverse element pivot+1 to end
    int i = pivot+1,j = n-1;
    while(i<=j){
        swap(arr[i],arr[j]);
        i++,j--;
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}