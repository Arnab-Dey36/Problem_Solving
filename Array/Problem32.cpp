#include<iostream>
#include<vector>
#include<set>
#include <algorithm>
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

    /* Problem: Three Sum
    Explain: Given an integer array arr, return all the unique triplets [arr[i], arr[j], arr[k]] 
    such that i != j, i != k, and j != k, and arr[i] + arr[j] + arr[k] == 0.

    Note: The triplets must be returned in sorted order, 
    the solution vector should also be sorted, and the answer must not contain any duplicate triplets.
    */
   
    /*Brute Force:Using three nested loops 
    1. Use three nested loops to generate all possible triplets.
    2. For each triplet, check if the sum is zero.
    3. If the sum is zero, create a vector to store the triplet and sort it.
    4. Add the triplet to the result.
    5. To avoid duplicates, use a set to store the unique triplets.

    Time Complexity: O(n^3) - The three nested loops result in a cubic time complexity.
    Space Complexity: O(n) - The space used to store the unique triplets in the set.
    */

    set<vector<int>> result;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(arr[i]+arr[j]+arr[k]==0){
                    vector<int> triplet = {arr[i], arr[j], arr[k]}; // Create a vector to store the triplet
                    sort(triplet.begin(), triplet.end());
                    result.insert(triplet);
                }
            }
        }
    }
    
    //print the unique triplets
    cout<<"The Unique Triplets are: "<<endl;
    for(auto triplet: result){
        cout<<"[";
        for(int i=0;i<triplet.size();i++){
            cout<<triplet[i];
            if(i!=triplet.size()-1){
                cout<<", ";
            }
        }
        cout<<"]"<<endl;
    }

    return 0;
}