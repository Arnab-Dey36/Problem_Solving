#include <iostream>
using namespace std;

int Ncr(int n, int r) {
   
    long long res = 1;
    for (int i = 0; i < r; i++) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

//print Nth row of Pascal's Triangle
void print(int n) {

    int ans = 1;

    cout << ans << " ";

    for (int i = 1; i < n; i++) {

        ans = ans * (n - i);
        ans = ans / i;

        cout << ans << " ";
    }

    cout << endl;
}


int main()
{
    int r,c;
    cout << "Enter The Row and Column: ";
    cin >> r >> c;
   
    int arr[r][c];
    cout << "Enter The Array Elements: ";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }

    /*Problem: Pascal's Triangle
    Q1:Given Row and Column, Find the Value at that Position*/

    /*Brute Force Approach:
    1. Use the formula NCr = N! / (R! * (N-R)!) to calculate the value at the specified row and column.
    2. Optimized the formula to avoid calculating factorials directly.
    Time Complexity: O(r), Space Complexity: O(1)
    */

    cout << "The Value at Row " << r << " and Column " << c << " is: " <<Ncr(r - 1, c - 1) << endl;

    /*Q2: Print Any Nth Row of Pascal's Triangle*/

    print(r);

   
    // input: 1 1 1 1 2 1 1 3 3 1 1 4 6 4 1 1 5 10 10 5 1

   

}