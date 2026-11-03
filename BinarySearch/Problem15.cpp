#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int main(){
    int n1,n2;

    cout<<"Enter The Size of 1st Array: ";
    cin>>n1;

    cout<<"Enter The Size of 2nd Array: ";
    cin>>n2;

    vector<int>arr1(n1);
    cout<<"Enter Elements Array 1: ";
    for(int i =0;i<n1;i++){
        cin>>arr1[i];
    }

    vector<int>arr2(n2);
    cout<<"Enter Elements Array 2: ";
    for(int i =0;i<n2;i++){
        cin>>arr2[i];
    }
    

    /*Problem: Median of two Sorted Arrays of Different Sizes  */

    /** Brute Force Algorithm:
     * Merge Two Sorted Array in extra another Array called merge
     * Then find the median:
     *      - for odd case, size of merge array divided by 2
     *      - for even case, we found two median, how to find? 
     *              -for 1st median, size of merge array divide by 2
     *              -for 2nd median, size of merge array -1 divide by 2
     *      - Now final median is (1st median + 2nd median)/2;
    */

    vector<int>merge;
    int left = 0,right=0;
    while(left<n1 && right<n2){
        if(arr1[left]<=arr2[right]){
            merge.push_back(arr1[left]);
            left++;
        }
        else{
            merge.push_back(arr2[right]);
            right++;
        }
    }
    //if left element still present
    while (left<n1)
    {
        merge.push_back(arr1[left]);
        left++;
    }
    
    //if right element still present
    while (right<n2)
    {
        merge.push_back(arr2[right]);
        right++;
    }

    int n = n1+n2;

    //if merger array is odd 
    if(n%2 == 1){
        cout<<"Median is: "<<merge[n/2]; //if print index then simply print --> n/2
        return 0;
    }
    double median = (merge[n / 2] + merge[n / 2 - 1]) / 2.0;
    cout<<"Median is: "<<median;
    return 0;
    
}