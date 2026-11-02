#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main(){
    int n,target;
    cout<<"Enter Size: ";
    cin>>n;

    int arr[100];
    cout<<"Enter The Array Elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    /* Problem: Find Missing Number*/
    
    /*Brute Force:
    1. Using Lenar Search: pick each element and check exit or not in an given array, 
    if not exit then this is my missing number.
            Time Complexity = O(n^2) and Space Complexity = O(1) 
    */
    for(int i=1;i<n;i++){
        int flag = 0;
        for(int j=0;j<n-1;j++){
            if(arr[j] == i)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            cout<<"Missing Element is: "<<i;
        }
    }

    /* Optimal Solution:
    1. Calculate Sum of all element in an given Array
    2. Calculate sum of all N-natural number.
    3. Calculate Difference b/w sum of all N-natural number & Sum of all element in an given Array.
    NOTE: In this case, when we take input from the user, the input loop will be 0 to n-1
            Time Complexity = O(n) and Space Complexity = O(1) 
    */

    //Sum of all element in an given Array
    int sum = 0;
    for(int i=0;i<n-1;i++){
        sum += arr[i];
    }
    //sum of all N-natural number
    int ans = n*(n+1)/2;

    cout<<"Missing Element is: "<<ans-sum;

}