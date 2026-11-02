#include <iostream>
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

    /*Problem: Rotate Matrix by 180 Degrees*/

    /*Brute Force Approache:
    1.Rotate 90 Degree in Two times
    */

    /*Optimized Approache:
    1.Reverse Row --> then Reverse Col
                or
    2.Reverse col --> Reverse Row
    */
   //Reverse Row
   for(int i=0;i<n;i++){
    int st=0,end=n-1;
    while(st<end){
        swap(arr[i][st],arr[i][end]);
        st++,end--;
    }
   }
   //Reverse Col
   for(int j=0;j<n;j++){
    int st=0,end=n-1;
    while(st<end){
        swap(arr[st][j],arr[end][j]);
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