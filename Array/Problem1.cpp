
/* Problem-1: Find Min and Max Element in Given Array. */

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

    int Max_Ele = INT_MIN,Min_Ele = INT_MAX;
    //Find Max
    for (int i = 0; i < n; i++)
    {
        if(arr[i]>Max_Ele)
        Max_Ele = arr[i];
    }
    
    //Find Min
    for (int i = 0; i < n; i++)
    {
        if(arr[i]<Min_Ele)
        Min_Ele = arr[i];
    }

    //Optimized
    for(int i=0;i<n;i++){
        Max_Ele = max(Max_Ele,arr[i]);
        Min_Ele = min(Min_Ele,arr[i]);
    }

    
    cout<<"Max Element: "<<Max_Ele<<endl;
    cout<<"Min Element: "<<Min_Ele;
}