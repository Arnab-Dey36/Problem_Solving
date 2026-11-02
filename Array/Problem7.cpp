#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter The Size Of Array: ";
    cin>>n;

    //input array
    int arr[100];
    cout<<"Enter the Arrays Elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //Majority Elements (Leetcode Problem)
    /*Brute Froce Approche-> O(n2): Frequency Calculate karo har element 
    kitne bar aaya hai then usko comapare karo if n/2 se jada bar
    aya to vohi mejority element hai.
    Ex:-[2,2,1,1,1]  here n=5 then n/2 = 5/2 =2.5 = 2, Matlab jo 
    Element 2 time se jayda bar ayaga wohi mejority element hoga.
    */
    
    for(int i=0;i<n;i++){
        int freq = 0;
        for(int j=0;j<n;j++){
            if(arr[j] == arr[i])
            freq++;
        }
        if(freq>n/2){
            cout<<"Majoriy Element is: "<<arr[i];
            return 0;   // stop after finding it
        }
    }
    cout<<"No Majoriy Element";

    /*Optimized Method->O(nlogn):
    1st sort the Array, after sorting, let the first element is the Majority element and uske liya uska
    freq=1 hoga then start loop at index 1 and check,jis index pe ho uska phele wala index value agar same hai
    to freq ko ++ karo otherwise agar same nhai hai to freq ko reset karo 1 pe and ans ke andar us index
    ka value ko dalo aab wo Majority element ho jayga.
    After that check karo freq greater hai ki nahi n/2 se agar greater hai answer ke andar jo value hai usko 
    return kar do.
    */

    //sort first then
    int freq = 1,ans=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i] == arr[i-1])
        freq++;
        else{
            freq = 1;
            ans = arr[i];
        }
    }
    if(freq>n/2)
    {
        cout<<ans;
    }


    /*Moore's voting Algorithm O(n): agar aisa ek mejority element jiska freq greater than n/2 hai vo
    iss array ke anadar exist karta hai to Moore's voting algo khata hai ki agar hum sare ka sare
    elements ki saruat se freq tarck karna start kare to humesa mejority element kai frequency
    jayda hoga.*/

    int freq = 0,ans = 0;
    for(int i=0;i<n;i++){
        if(freq == 0)
        ans = arr[i];

        if(ans == arr[i]) freq++;

        else freq--;
    }

    cout<<ans;


   /*Moore's Voting Algorithm:
   1. Initialize a variable count to 0 and a variable candidate to None.
   2. Traverse the array from left to right.
    3. If count is 0, set candidate to the current element and increment count.
    4. If the current element is equal to candidate, increment count.
    5. If the current element is not equal to candidate, decrement count.
    6. After traversing the array, candidate will be the majority element.
   */


}

    

