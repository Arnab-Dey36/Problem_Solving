
#include<iostream>
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

    //MaxSubArray Sum(Brute Force)
    int maxSum = INT_MIN,length = 0;
    for(int st=0;st<n;st++){
        int currSum = 0;
        for(int end=st;end<n;end++){
            currSum += arr[end];
            maxSum = max(currSum,maxSum);
            length = max(length,end-st+1);
        }
    }

    // cout<<"Max Sub Array Sum is: "<<maxSum<<endl;
    // cout<<"Max Sub Array length is: "<<length<<endl;

    //MaxSubArray Sum(Optimized Method Using Kadane's Algorithm:O(n)<--Time Complexity)
    /*Kadane's Algorithm:
    1. Initialize two variables MaxSum and CurrSum to the smallest possible integer value (INT_MIN) and 0, respectively.
    2. Iterate through each element of the array.
    3. For each element, add it to CurrSum.
    4. Update MaxSum to be the maximum of MaxSum and CurrSum.
    5. If CurrSum becomes negative, reset it to 0 (this is the key step of Kadane's Algorithm).
    6. Time Complexity: O(n) & Space Complexity: O(1)
    */
    int MaxSum = INT_MIN,CurrSum = 0;
    for(int i=0;i<n;i++){
        CurrSum += arr[i];
        MaxSum = max(CurrSum,MaxSum);

        //Apply Kadane's Algorithm 
        if(CurrSum<0)
        CurrSum = 0;
    }
    cout<<"Max Sub Array Sum is: "<<MaxSum;
}





/*
    Problem: Max SubArray Sum
    Ex:[1,2,3,4,5]

    Method: Brute Forece
    
    Start      End
      0         0,1,2,3,4   <--- This are index number -->[0],[0,1],[0,1,2],[0,1,2,3],[0,1,2,3,4]<-- this are subArray
      1         1,2,3,4     <--[1],[1,2],[1,2,3],[1,2,3,4] --> baki ka bhi same process
      2         2,3,4
      3         3,4
      4         4

    Now we see pattern, Start always zero last tak(n tak) ja raha hai Aur End ekbar zero ke liye zero se end tak,
                                                                              ekbar one ke liya one se end takk
                                                                              ekbar Two ke liya Two se end ja raha hai
                                            Basically, End har bar start se n-1(end) tak ja raha hai.
    Optimized Approche: 
    Kadane's Algorithm: It say that if current sum value < 0 means Negative then it make to be zero,for example, currentSum = -15 means less than zero.So it make to be become zero , now currentSum = 0.
*/