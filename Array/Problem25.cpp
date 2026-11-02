#include <iostream>
#include <vector>

using namespace std;

// Mark the entire row with -1
// void markRow(vector<vector<int>>& arr, int i, int m){
//     for(int j = 0; j < m; j++){
//         if(arr[i][j] != 0){
//             arr[i][j] = -1;
//         }
//     }
// }

// // Mark the entire column with -1
// void markColumn(vector<vector<int>>& arr, int j, int n){
//     for(int i = 0; i < n; i++){
//         if(arr[i][j] != 0){
//             arr[i][j] = -1;
//         }
//     }
// }

int main(){

    int n, m;

    cout << "Enter rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    cout << "Enter matrix elements: ";

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    /* Problem: Set Matrix Zeroes

    Brute Force Approach:
    1. Traverse the matrix and find the elements which are 0.
    2. Whenever a 0 is found, mark the entire row and column -1.
    3. Traverse the matrix again.
    4. Convert all -1 to 0.
    5. Time Complexity: O(n*m)*(n*m)+(n*m) and Space Complexity: O(n+m)
    */

    // // Traverse matrix and mark rows and columns
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){

    //         if(arr[i][j] == 0){

    //             markRow(arr, i, m);
    //             markColumn(arr, j, n);
    //         }
    //     }
    // }

    // // Convert marked elements to 0
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){

    //         if(arr[i][j] == -1){
    //             arr[i][j] = 0;
    //         }
    //     }
    // }

    /*Better Approach:
    1. Use two arrays with size n and m to keep track of the rows and columns that need to be marked.
    2. Traverse the matrix and whenever a 0 is found, mark 1 in the corresponding row and column arrays.
    3. Traverse the matrix again and check the row and column arrays to see if they are marked or not. If marked, then set the element to 0.
    4. Time Complexity: O(n*m) and Space Complexity: O(n+m)
    */

    // Create two arrays to keep track of rows and columns
    int row[n] = {0};
    int col[m] = {0};
    // Traverse matrix and mark rows and columns
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){

            if(arr[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    // Traverse matrix and set elements to 0 based on marked rows and columns
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(row[i] == 1 || col[j] == 1){ // if either the row or column is marked, set the element to 0
                arr[i][j] = 0;
            }
        }
    }

    /* Optimal Approach:
    1. Use the first row and first column of the matrix as markers to indicate which rows and columns need to be set to 0.
    2. Traverse the matrix from the second row and second column onwards.
    3. If an element is 0, set the corresponding element in the first row and first column to 0.
    4. Traverse the matrix again from the second row and second column onwards.
    5. If the corresponding element in the first row or first column is 0, set the current element to 0.
    6. Finally, check if the first row or first column itself needs to be set to 0.
    7. Time Complexity: O(n*m) and Space Complexity: O(1)
    */

    // Print matrix
    cout << "Final Matrix:\n";

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}