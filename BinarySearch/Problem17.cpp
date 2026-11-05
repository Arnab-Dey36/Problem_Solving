#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int main(){
    int n1,n2,target;

    cout<<"Enter The Size of Row: ";
    cin>>n1;

    cout<<"Enter The Size of Column: ";
    cin>>n2;

    cout<<"Enter The Target Element: ";
    cin>>target;

    int arr[100][100];
    cout<<"Enter Array Elements: ";
    for(int i=0;i<n1;i++){
        for(int j = 0;j<n2;j++){
            cin>>arr[i][j];
        }
    }    
    

    /*Problem: Search in a Row-Column Sorted  */

    /** Brute Force Algorithm:
     * Traverse the every row and column means traverse the entire 2D matrix and check if the target element is present or not.
    */
//    for(int i=0;i<n1;i++){
//        for(int j=0;j<n2;j++){
//            if(arr[i][j]==target){
//                cout<<"Element Found at: "<<i<<","<<j;
//            }
//        }
//        cout<<endl;
//    }
//     return 0;

    /** Better Approach:
     * Traverse the first Row and check if the target element is present or not.
     * If the target element is present in the first row then apply Binary Search on that row to find the target element.
     * If the target element is not present in the first row then move to the next row and repeat the same process until the target element is found or all rows are traversed.
     * Time Complexity: O(n)+O(logm) where n is the number of rows and m is the number of columns. and Space Complexity: O(1)
     */

    // for(int i = 0;i<n1;i++){
    //     //Checheck if the target element is present or not on that row
    //     if(arr[i][0]<=target && target<=arr[i][n2-1]){
    //         int st=0,end=n2-1;
    //         while (st<=end)
    //         {
    //             int mid = st+(end-st)/2;
    //             if(arr[i][mid] == target){
    //                 cout<<"Present at index: "<<i<<","<<mid<<endl;
    //                 cout<<"Present!!";
    //                 return 0;
    //             }

    //             else if(arr[i][mid]>target) end = mid-1;

    //             else st = mid+1;

    //         }
            
    //     }
    // }
    // cout<<"Not Present!!";
    // return 0 ;


    /**Optimized Approach:
     * st = 0, end = col-1
     * check if the target element is equal to the target element then return the index of that element.
     * if the current element is greater than the target element then move column--;\
     * if the current element is less than the target element then move row++.
     * 
     * time Complexity: O(n+m) where n is the number of rows and m is the number of columns. and Space Complexity: O(1)
    */
   int row = 0,col=n2-1; //where n1= ROw and n2 = col
   while (row<n1 && col>=0)
   {
    if(arr[row][col] == target){
        cout<<"Present!!"<<endl;
        cout<<"Present at index: "<<row<<","<<col;
        return 0;
    }
    else if(arr[row][col]>target) col--;

    else row++;
   }
   
  cout<<"Not Present!!";
  return 0;

}    