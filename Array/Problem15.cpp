#include <iostream>
#include <set>
#include<vector>
using namespace std;
int main()
{
    int n, target;
    cout << "Enter Size: ";
    cin >> n;

    int arr1[100];
    cout << "Enter The Elements in Array1: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    int arr2[100];
    cout << "Enter The Elements in Array2: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }

    /* Problem: Intersection Of Two Sorted Arrays */

    /* Brute Force: 
    1. Pick one element from Arr1 either Arr2 
    2. Check this element is present or not in another Array
    3. If present marked it 1 in visited array and put this element in ans Array
    4. If Arr1 iteration complete first then stop menas break while ignoring arr2 iteration complete or not and vice verse. 
            T.C --> O(n1*n2) here we same size of two Array
            S.C-->O(n2) either O(n1);
    */
    vector<int>visited(n,0);
    vector<int>ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr1[i] == arr2[j] && visited[j] == 0){
                ans.push_back(arr1[i]);
                visited[j] = 1;
                break;;
            }
            if(arr2[j]>arr1[i]) break;
        }
    }
    for(int val: ans){
        cout<<val<<" ";
    }

}