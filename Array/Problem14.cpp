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

    /* Problem: Union of Two Sorted Array */

    /* Brute Force: T.C-->O(n1logn + n2logn +o(n1+n2))    & S.C-->O(n1+n2)+O(n1+n2)
    1. Put both Array elemnt in the set because set store the unique element.
    2. Create an array called union and size will be same as Set
    3. take element from the set put in array(Union).And after this print the array
    */

    set<int>st;
    //Put array1 element in set
    for(int i=0;i<n;i++){
        st.insert(arr1[i]);
    }

    //Put array2 element in set
    for(int i=0;i<n;i++){
        st.insert(arr2[i]);
    }
    // Create a new array put the all set element in new array
    vector<int>ans;
    //Simply Iterato kiya and new array ke sare andar element ko fill kiya.
    for(auto it : st){
        ans.push_back(it);
    }

    //print
    for(int i=0;i<st.size();i++){
        cout<<ans[i]<<" ";
    }

}