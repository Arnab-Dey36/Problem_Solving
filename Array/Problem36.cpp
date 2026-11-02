#include<iostream>
#include<vector>
#include<set>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cout<<"Enter The Size: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter The Array Elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    /*Problem: Repeating and Missing Numbers */

    /*Brute Force Approach:
    1. Check every number(1 to n) one by one from given array present or not.
    2. Count the number of times it is present in the array.
    3. If an element is found more than once, it is the repeating number and put in repeating variable.
    4. If an element is not found in the array, it is the missing number and put in missing variable.

    Time Complexity: O(n^2) - The array is traversed twice.
    Space Complexity: O(1) - No additional space is used.
    */

    int missing = -1, repeating = -1;
    for(int i = 1;i<=n;i++){
        int count = 0;
        for(int j = 0;j<n;j++){
            if(arr[j] == i)
            count ++;
        }

        if(count == 2) repeating = i; // If count is 2, it means the number is repeating
        else if(count == 0) missing = i; // If count is 0, it means the number is missing
        if(count == 0) missing = i;

        // If both repeating and missing numbers are found, break the loop
        if(repeating != -1 && missing != -1)
        break;

    }

    cout<<"Repeating Number: "<<repeating<<endl;
    cout<<"Missing Number: "<<missing<<endl;

    /*Optimized Approach:
    1. Use a set to store the elements of the array.
    2. Iterate through the array and check if each element is already in the set.
    3. If an element is already in the set, it is the repeating number.
    4. If an element is not in the set, add it to the set.
    5. After processing all elements, iterate from 1 to n and check which number is missing from the set.
    Time Complexity: O(n) - The array is traversed once.
    Space Complexity: O(n) - A set is used to store the elements.
    */
   set<int> s;
    for(int i = 0; i < n; i++) {
        if(s.find(arr[i]) != s.end()) {
            repeating = arr[i];
        } else {
            s.insert(arr[i]);
        }
    }

    for(int i = 1; i <= n; i++) {
        if(s.find(i) == s.end()) {
            missing = i;
            break;
        }
    }

    cout<<"Repeating Number: "<<repeating<<endl;
    cout<<"Missing Number: "<<missing<<endl;

    /*Optimized Approach: Using Mathematical Formula 
    1. Calculate the sum of all elements in the array.
    2. Calculate the sum of all numbers from 1 to n.
    3. The difference between these two sums is x-y, where x is the repeating number and y is the missing number.
    4. Calculate the sum of squares of all elements in the array.
    5. Calculate the sum of squares of all numbers from 1 to n.
    6. The difference between these two sums is x^2-y^2, which can be factored as (x-y)(x+y).
    7. Now we have two equations:
        a. x - y = sum(arr) - sum(1 to n)
        b. x + y = (sum of squares of arr - sum of squares of 1 to n) / (x - y)
    8. Solve these two equations to find x and y.
    Time Complexity: O(n) - The array is traversed once.
    Space Complexity: O(1) - No additional space is used.
    */

    //Sum of first n natural numbers
    long long sum_n = (n * (n + 1)) / 2;
    //Sum of squares of first n natural numbers
    long long sum_n_sq = (n * (n + 1) * (2 * n + 1)) / 6;

    long long sum_arr = 0, sum_arr_sq = 0;
    for(int i = 0; i < n; i++) {
        sum_arr += arr[i];
        sum_arr_sq += (long long int)arr[i] * arr[i];
    }
    // x - y = sum(arr) - sum(1 to n)
    long long diff = sum_arr - sum_n; // x - y
    // x^2 - y^2 = sum(arr^2) - sum(1 to n)^2
    long long diff_sq = sum_arr_sq - sum_n_sq; // x^2 - y^2
    // x + y = (x^2 - y^2) / (x - y)
    long long sum = diff_sq / diff; // x + y

    long long repeating1 = (diff + sum) / 2;
    long long missing1 = sum - repeating1;

    cout<<"Repeating Number: "<<repeating1<<endl;
    cout<<"Missing Number: "<<missing1<<endl;

   
}