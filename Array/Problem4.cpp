#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter The Size: ";
    cin>>n;

    int arr[100];
    cout<<"Enter The Elements: ";
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    //find Single element
    int ans = 0;
    for(int i=0;i<n;i++){
        ans = ans^arr[i];
    }

    // int ans = 0;
    // for(int i=0;i<n;i++){
    //      int count = 0;
    //     for(int j=0;j<n;j++){
    //         if(arr[i] == arr[j])
    //         count++;
    //     }
    //      if(count == 1) {
    //          ans = arr[i];
    //          break;
    //        } 
    // }

    cout<<ans;
}
/*
Same element ka XOR lene se vo ZERO ho jata hai
1 XOR 1 = 0
0 XOR 0 = 0
1 XOR 0 = 1
0 XOR 1 = 1

EX-1: [4 1 2 1 2] Sare element ka XOR le liya hu. Here 1^1 & 2^2 = 0 ,aab iss 0 ke sath 4 ka XOR lene hai like that:
4 = 100
0 = 000
Now, 4^0 = 4(ANS)

EX-2: [1 2 3 2 1]
= 1 ^ 2 ^ 3 ^ 2 ^ 1
= (1^1) ^ (2^2) ^ 3
= 0 ^ 0 ^ 3
= 3

Property: 1) n^n = 0  
          2) n^0 = n

*/