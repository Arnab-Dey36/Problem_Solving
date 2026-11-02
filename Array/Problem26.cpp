#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cout << "Enter The Row: ";
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

    /*Problem:Rotate The Matrix By 90 Degrees Clockwise*/

    /*Brute Force Approach:
    Create a new matrix of the same size.
    For each element in the original matrix, place it in the new matrix at the position (col, rows-1-row).
    Time Complexity: O(n^2), Space Complexity: O(n^2)
    */

    int ans [n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[j][n - 1 - i] = arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }


    /*Optimized Approach:
    1. Transpose the matrix at first.
    2. Reverse each row of the transposed matrix.
    Time Complexity: O(n*n)= O(n^2), Space Complexity: O(1)
    */

    // Transpose the matrix
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }

    // Reverse Each Row
    for(int i=0;i<n;i++){
        int st=0,end=n-1;
        while (st<end)
        {
           swap( arr[i][st],arr[i][end]);
           st++,end--;
        }
    }

    //Print
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

}