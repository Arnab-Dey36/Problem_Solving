#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter The Row and Column: ";
    cin >> n;
   
    int arr[n][n];
    cout << "Enter The Array Elements: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    /*Problem: Spiral Traversal of a Matrix
    Approach:
    1. Print the first row from left to right.And increment the top.
    2. Print the last column from top to bottom.And decrement the right.
    3. Print the last row from right to left.And decrement the bottom.
    4. Print the first column from bottom to top.And increment the left.
    5. Repeat the process for the inner layers of the matrix.
    Time Complexity: O(n*n)= O(n^2), Space Complexity: O(1) row = col = n
    */

    int top=0,left=0,right=n-1,bottom=n-1;

   while (top<=bottom && left<= right)
   {
        //print top
        for(int i=left;i<=right;i++){
            cout<<arr[top][i]<<" ";
        }
        top++;

        //print right
        for(int i=top;i<=bottom;i++){
            cout<<arr[i][right]<<" ";
        }
        right--;

        //print bottom:right to left
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                cout<<arr[bottom][i]<<" ";
            }
            bottom--;
        }
        
        
        //print left:bottom to top
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                cout<<arr[i][left]<<" ";
            }
            left++;
        }
        
   }
   
}