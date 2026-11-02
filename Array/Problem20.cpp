#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter Size: ";
    cin>>n;
    
    int arr[100];
    cout<<"Enter The Array Elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    /*Problem: Sort an array of 0s, 1s and 2s in a single pass.
    Example: [0, 1, 2, 1, 0, 2] -> [0, 0, 1, 1, 2, 2]
    */
    /* Brute Force Approach:
    Calculate the count of 0s, 1s and 2s in the array how many they are present.
    Then, fill first the array with 0s, then 1s and then 2s.
    Time Complexity = O(N) & Space Complexity = O(1)
    */
   int count0=0,count1=0,count2=0;
   for(int i=0;i<n;i++){
    if(arr[i] == 0) count0++;
    if(arr[i] == 1) count1++;
    if(arr[i] == 2) count2++;
   }

   //Now fill zero first then 1 then 2
   for(int i=0;i<count0;i++){
    arr[i] = 0;
   }
   for(int i = count0;i<count0+count1; i++){
    arr[i] = 1;
   }
   for(int i = count0+count1;i<n; i++){
    arr[i] = 2;
   }

   /*Dutch National Flag Algorithm:
   This algorithm is used to sort an array of 0s, 1s and 2s in a single pass.
   It uses three pointers: low, mid and high.
   low points to the end of the 0s section.
   mid points to the current element.
   high points to the start of the 2s section.
    1. Initialize low=0, mid=0 and high=n-1
    2. Traverse the array from mid to high
    3. If arr[mid] == 0, swap arr[low] and arr[mid], increment low and mid.
    4. If arr[mid] == 1, increment mid.
    5. If arr[mid] == 2, swap arr[mid] and arr[high], decrement high.
    6. Time Complexity = O(N) & Space Complexity = O(1)
   */
    int low=0,mid=0,high=n-1;
    for(int i=mid;i<high;i++){
        if(arr[mid] == 0){
            swap(arr[low],arr[mid]);
            low++,mid++;
        }
        if(arr[mid] == 1) mid++;

        if(arr[mid] == 2)
        {
            swap(arr[mid],arr[high]);
            high--;
        }
    }
        //OR
    while(mid<=high){
        if(arr[mid] == 0){
            swap(arr[low],arr[mid]);
            low++,mid++;
        }
        else if(arr[mid] == 1) mid++;

        else
        {
            swap(arr[mid],arr[high]);
            high--;
        }
    }




   //Print 
   for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
   }

}