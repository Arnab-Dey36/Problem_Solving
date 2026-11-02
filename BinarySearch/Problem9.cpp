#include<iostream>
using namespace std;

int main(){
    int x;

    cout<<"Enter The Value To Find Square Root: ";
    cin>>x;


    /* Problem: Binary Search for Square Root */

    /* Alogorithm:
    1. Initialize start = 0, end = n, and ans = -1.
    2. While start <= end:
        a. Calculate mid = start + (end - start) / 2
        b. If mid * mid == n, return mid or store it in the answer variable and break
        c. If mid * mid > n, set end = mid - 1
        d. Otherwise, store mid in ans and set start = mid + 1.
    3. Return the last valid answer
    */

    /** NOTE:
     * Instead of wright if and else condition separately we can merge them into one condition as follows:
     * if(mid * mid <=n) {
     *   ans = mid;
     *  st = mid+1;
     * }
     * else end = mid-1;
    */

   int st = 0,end = x,ans = -1;

   while (st<=end)
   {
    int mid = st+(end-st)/2;
    if(mid * mid == x){
        ans = mid;
        break;
    }
    else if(mid*mid>x) end = mid-1;

    else{
        ans = mid;
        st = mid+1;
    }
   }
   
   cout<<ans;
}

