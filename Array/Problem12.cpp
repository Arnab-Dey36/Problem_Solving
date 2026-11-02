#include<iostream>
#include<vector>
using namespace std;

void reverseArray(int arr[],int st,int end){
    while(st<end){
        swap(arr[st],arr[end]);
        st++,end--;
    }
}


int main(){
    int n,d;
    cout<<"Enter The Size: ";
    cin>>n;

    int arr[100];
    cout<<"Enter The Arrays Elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Enter The d: ";
    cin>>d;

    /* Problem: Left Rotate an Array by D Places */

    /*
    Brute Force: 1. Store 1st d-element in temporarily variable
           2. Shift remaining elements to the left
           3. Put temp elements at the end
    */

     
    //Store 1st D elements
    // vector<int> temp;
    // for(int i=0;i<d;i++){
    //     temp.push_back(arr[i]);
    // }

    // //Shifting
    // for(int i = d;i<n;i++){
    //     arr[i-d] = arr[i];
    // }

    // //put temp in last
    // for(int i=n-d;i<n;i++){
    //     arr[i] = temp[i-(n-d)];
    // }


    /*
    Optimized:  T.C->O(n) & S.C-->O(n)
    1. Reverse The Element from 0 to d
    2. Reverse The element from d+1 to n
    3. Finally Reverse the entire Array
    */
    
    //Reverse first d elements
    reverseArray(arr,0,d-1);

    //Reverse remaining elements
    reverseArray(arr,d,n-1);

    //Reverse entire array
    reverseArray(arr,0,n-1);

    //print array
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }


}