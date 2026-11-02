#include<iostream>
#include<vector>
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

    /* Product Of Array Except Self (Leetcode-238)*/
    /*
    Brute Froce 1: 
    1. Calculate total product of all element. 
    2. Divide total product by Each ELement.
    Example:[1,2,3,4] ==> TotalProduct = 24
    Now, 24 Devide 1 = 24  
         24 Devide 2 = 12  
         24 Devide 3 = 8 
         24 Devide 4 = 6  
    Output = [24,12,8,6]
    */
    
    //calculate total product
    // int pro = 1;
    // for(int i=0;i<n;i++){
    //     pro *= arr[i];
    // }
    // //divide total product by each ELements
    // vector<int>ans(n);
    // for(int i=0;i<n;i++){
    //     ans[i] = pro/arr[i];
    // }
    // //finally print the ans;
    // for(int val:ans){
    //     cout<<val<<" ";
    // }

    /*
    Brute Froce 2: o(n2) 
    Using Nested loop
    ek inner loop lagao for move i 
    then ek outer loop j lagao product ko calculate karne ke liya 
    condition iea hai j != i(i) hoga then product ke andar add karna hai.
    */
    //    vector<int>ans(n);
    //    for(int i=0;i<n;i++){
    //         int product = 1;
    //         for(int j=0;j<n;j++){
    //             if(arr[j] != arr[i]){
    //                 product *= arr[j];
    //             }
    //         }
    //         ans[i] = product;

    //     }
    //     for(int val:ans)
    //     cout<<val<<" ";

    /* Optimized: T.C-> O(n) & S.C->O(n)
    1.Calculate Prefix and Suffix
    2. Multiply prefix and suffix 
    */

    // vector<int>ans(n);
    // vector<int>pre(n,1);
    // vector<int>suff(n,1);
    // //prefix
    // for(int i=1;i<n;i++){
    //     pre[i] = pre[i-1] * arr[i-1];
    // }
    
    // //suffix
    // for(int i=n-2;i>=0;i--){
    //     suff[i] = suff[i+1] * arr[i+1];
    // }
    
    // //put the value in ans
    // for(int i=0;i<n;i++){
    //     ans[i] = pre[i] * suff[i];
    // }
    
    // for(int val:ans){
    //     cout<<val<<" ";
    // }


    // To reduce space complexity--> O(1) And T.c-->O(n)
    vector<int>ans(n,1);
    
    //Calculate the prefix in ans directly
    for(int i=1;i<n;i++){
        ans[i] = ans[i-1] * arr[i-1];
    }
    
    //Suffix calculate directly
        int suffix = 1;
    for(int i=n-2;i>=0;i--){
        suffix *= arr[i+1];
        ans[i] *= suffix;
    }
    
    
    for(int val:ans){
        cout<<val<<" ";
    }
}