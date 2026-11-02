#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,target;
    cout<<"Enter The Size: ";
    cin>>n;

    int arr[100];
    cout<<"Enter The Arrays Element: ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    vector<int>ans;

    cout<<"Enter The Target: ";
    cin>>target;
    
    //Brute Force Approche
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j] == target)
            {
                ans.push_back(arr[i]);
                ans.push_back(arr[j]);
                break;
            }
        }
    }
    //output
    for(int x : ans){
        cout<<x<<" ";
    }

    //Otimized Approche-Two pointer Approche(Condition: Array ko Sort hona chahiya)
    int st=0,end=n-1;
    while (st<end)
    {
        if(arr[st]+arr[end] == target)
        {
            ans.push_back(arr[st]);
            ans.push_back(arr[end]);
            break;
        }
        else if(arr[st]+arr[end]>target)
        end--;

        else st++;
    }

    cout<<arr[st]<<" "<<arr[end];
    
}