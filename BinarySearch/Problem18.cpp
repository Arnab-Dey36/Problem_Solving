#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;

    cout << "Enter The Size of Row: ";
    cin >> n;

    cout << "Enter The Size of Column: ";
    cin >> m;

    int arr[100][100];
    cout << "Enter Array Elements: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    /*Problem: Median in a Row Wise Sorted Matrix  */

    /**Algorithm:
     * Create an empty array
     * Traversed orginal 2D matrix all element and put them into this extra array
     * Sort this extra Array and now find the medina using this formula: extra_arr[n*m]/2; where n = row and m = column
     * Time Complexity: O(n*m) + O(n*m*log(n*m)) = O(n*m*log(n*m))
    */

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans.push_back(arr[i][j]);
        }
    }

    sort(ans.begin(), ans.end());
    int median = ans[(n * m) / 2];
    cout << "The Median is: " << median << endl;
}