#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int main(){
    int n;
    cout<<"Enter The Size: ";
    cin>>n;

    int arr[100];
    cout<<"Enter The Array Elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }

    /*Problem:Longest Consecutive Sequence in an Array
    Consecutive elements are those elements which are present in the array and they are in increasing order.
    */

    /*Optimal Approach:
    1. Use a set to store all the elements of the array.
    2. Iterate through the array and for each element, check if its previous element is present in the set.
    3. If not present, then it is the start of a new sequence.
    4. Count the length of the sequence starting from that element.
    5. Return the maximum length found.

    Time Complexity: O(n) and Space Complexity: O(n)
    */
   vector<int>ans2;
    unordered_set<int> s;
    for(int i=0;i<n;i++){
        s.insert(arr[i]);
    }
    int maxCount2 = 0;
    for(int i=0;i<n;i++){
        if(s.find(arr[i]-1) == s.end()){
            int count2 = 1;
            int currentNum = arr[i];
            while(s.find(currentNum+1) != s.end()){
                count2++;
                currentNum++;
            }
            maxCount2 = max(maxCount2,count2);
        }
    }
    cout<<"The Length of Longest Consecutive Sequence is: "<<maxCount2<<endl;
}

/*Brute Force Approach:
    1. Traverse the matrix and find the elements which are 0.
    2. Whenever a 0 is found, mark the entire row and column -1.
    3. Traverse the matrix again.
    4. Convert all -1 to 0.
    5. Time Complexity: O(n*m) and Space Complexity: O(n+m)
    */