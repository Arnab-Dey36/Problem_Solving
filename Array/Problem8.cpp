#include<iostream>
#include<set>
using namespace std;

int main(){
    int n,target;
    cout<<"Enter Size: ";
    cin>>n;

    int arr[100];
    cout<<"Enter The Array Elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // Remove Duplicate
    //step-1: Put All element in set 
    set<int>s;
    for(int i=0;i<n;i++){
        s.insert(arr[i]);
    }

    //Step-2: Set se Element ko nikalo aur index 0 array ke fill karo
    int index = 0;
    for(auto it:s){
        arr[index] = it;
        index++;
    }
    //Print After Remove Duplicate
    for(int i=0;i<index;i++){
        cout<<arr[i]<<" ";
    }

    //Optimized Approche
    int i = 0;
    for(int j=1;j<n;j++){
        if(arr[j] != arr[i]){
            arr[i+1] = arr[j];
            i++;
        }
    }  
    // cout<<i+1; //Return size of Arraay
    for(int k=0;k<=i;k++){
        cout<<arr[k]<<" ";
    }
}
