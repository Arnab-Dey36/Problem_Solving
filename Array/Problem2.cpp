
/* Problem-2: Reverse The Given Array */

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

    //Reverse Array: Using Two Pointer Approche
    int st = 0, end = n-1;
    while(st<end){
        swap(arr[st],arr[end]);
        st++,end--;
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}