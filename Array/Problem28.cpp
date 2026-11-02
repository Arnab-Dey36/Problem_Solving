#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter The Row and Col: ";
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

    /*Problem: Rotate Matirx By 90 Degree Anticlockwise */

    /*Approche to Solved:
    1.Reverse The Row ---> Then Transpose the matrix
    */

    //Reverse Row
    for(int i=0;i<n;i++){
        int st=0,end=n-1;
        while(st<end){
            swap(arr[i][st],arr[i][end]);
            st++,end--;
        }
    }
    //Transpose Matrix
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            swap(arr[i][j],arr[j][i]);
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