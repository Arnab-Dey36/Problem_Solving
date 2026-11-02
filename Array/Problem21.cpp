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


    /*Problem: Rearrange array elements by sign
    Example: [3,1,-2,-5,2,-4] -> [3,-2,1,-5,2,-4]
    */

    /*Brute Force Approach:
    1. Create two separate arrays for positive and negative numbers.You can consider using vectors for this purpose.
    2. Traverse the original array and place each element in the appropriate array,means 
    if the element is positive, place it in the positive array, and 
    if it is negative, place it in the negative array.
    3. Merge the two arrays back into the original array.Loop will run n/2 times because we are merging two arrays of size n/2 each.
    4. Time Complexity: O(n)+O(n/2) & Space Complexity: O(n)
    */

    vector<int>pos,neg;
    //place positive and negative numbers in separate arrays
    for(int i=0;i<n;i++){
        if(arr[i]>=0){
            pos.push_back(arr[i]);
        }
        else{
            neg.push_back(arr[i]);
        }
    }
    //merge the two arrays back into the original array
    for(int i=0;i<n/2;i++){
        
        arr[2*i]=pos[i];
        arr[2*i+1]=neg[i];

    }


    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    /*Optimized Above Time Complexity- O(n)+O(n/2) into O(n) space complexity remain same O(n)*/

    vector<int>ans(n,0);
    int posIndex=0,negIndex=1;
    for(int i=0;i<n;i++){
        if(arr[i]>=0){
            ans[posIndex] = arr[i];
            posIndex += 2;
        }
        else{
            ans[negIndex] = arr[i];
            negIndex += 2;
        }
    }

    /*Optimized Approach: Two Pointers
    1. Use two pointers, one for positive numbers and one for negative numbers.
    2. Traverse the array and place positive numbers at even indices and negative numbers at odd indices.
    3. Time Complexity: O(n) & Space Complexity: O(1)
    */
   int posIndex1=0,negIndex1=1;
   while(posIndex1<n && negIndex1<n){
       if(arr[posIndex1]>=0){
           posIndex1+=2;
       }
       else if(arr[negIndex1]<0){
           negIndex1+=2;
       }
       else{
           swap(arr[posIndex1],arr[negIndex1]);
           posIndex1+=2;
           negIndex1+=2;
       }
   }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    

}

