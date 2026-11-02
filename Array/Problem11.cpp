#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter The Size: ";
    cin>>n;

    int arr[100];
    cout<<"Enter The Arrays Elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    /* Problem: Left Rotate an Array by One Place */

    /*
    Logic: 1. Store 1st element in temporarily variable
           2. Move i-th element in i-1 position from their orginal position.
           3. Insert Temporarily varaible in the last position (n-1);

    matlab: 
           i always start 1 index and 1 index ki element ko move karke 0 ke index me
            leke ana hai baki element ka bhi same and last me temp ko add karna hai.
    */

    int temp = arr[0];
    for(int i=1;i<n;i++){
        //Move i-th element in i-1 position from their orginal position.
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}