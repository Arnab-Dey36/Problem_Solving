#include<iostream>
#include<vector>
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
    //Majority
    int ans = arr[0],freq=1;

    for(int i=1;i<n;i++){
        if(arr[i] != ans){
            freq++;
        }
        else{
            ans = arr[i];
            freq = 1;
        }

        if(freq>n/2){
            cout<<ans;
        }
    }
}

/*
Binay Exponentiation me hum apne power ki baniry from ke upar loop lagate hai matlab power ka binary from me jitna digit hai uske upar loop lagate hai.
For Example: 3^5 ==>   x^4 x^2 x^1
                    5 = 1   0   1
                       3^4 3^2 3^1
        ignore 0 wala,only count 1 wala --> 3^4 * 3^1 = 3^5 
*/