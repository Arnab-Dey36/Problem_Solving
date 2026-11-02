#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int main()
{
    int n, target;
    cout << "Enter The Size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter The Array Elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter The Target: ";
    cin >> target;

    /*Problem: Check 4 sum*/

    /*Brute Force:
    1.Sort the array
    2. use 2 nested loops to fix the first two elements.
    3. Use two pointers to find the other two elements .
    4.  i)If (sum == target) return true
        ii)If (sum < target) left++
        iii)If (sum > target) right--

    */

    // //sort the array
    // sort(arr.begin(),arr.end());

    // for(int i =0;i<n;i++){

    //     for(int j = i+1;j<n;j++){
    //         int left = j+1,right = n-1;

    //         while(left<right){
    //             long long sum = arr[i]+arr[j]+arr[left]+arr[right];

    //             if(sum == target)
    //             {
    //                 cout<<"Pressent"<<endl;
    //                 return 0;
    //             }

    //             else if (sum<target) left++;

    //             else right--;
    //         }
    //     }
    // }
    // cout <<"Not Present"<<endl;

    /*Problem-2: 4 Sum - All Quadruples*/

    /*Brute Force: Using 4 nested loops
    1. Use 4 nested loops to generate all possible quadruples.
    2. For each quadruple, check if the sum is equal to the target.
    3. If the sum is equal to the target, create a vector to store the quadruple and sort it.
    4. Add the quadruple to the result.
    Time Complexity: O(n^4) - The four nested loops result in a quartic time complexity.
    Space Complexity: O(n) - The space used to store the unique quadruples in the set.
    */
    // set<vector<int>> result;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         for (int k = j + 1; k < n; k++)
    //         {
    //             for (int l = k + 1; l < n; l++)
    //             {
    //                 long long sum = arr[i] + arr[j] + arr[k] + arr[l];
    //                 if (sum == target)
    //                 {
    //                     vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
    //                     sort(temp.begin(), temp.end());
    //                     result.insert(temp);
    //                 }
    //             }
    //         }
    //     }
    // }
    // // print the unique quadruples
    // cout << "The Unique Quadruples are: " << endl;
    // for (auto quadruple : result)
    // {
    //     cout << "[";
    //     for (int i = 0; i < quadruple.size(); i++)
    //     {
    //         cout << quadruple[i];
    //         if (i != quadruple.size() - 1)
    //         {
    //             cout << ", ";
    //         }
    //     }
    //     cout << "]" << endl;
    // }

    /*Optimized Approach: Using Two Pointers
    1. Sort the array.
    2. Use two nested loops to fix the first two elements.
    3. Use two pointers to find the other two elements.
    4. Check if the current element is the same as the previous element, if it is, skip it. Same for the second element.
    5. If the sum is equal to the target, add the quadruple to the result and move both pointers.
    6. If the sum is less than the target, move the left++.
    7. If the sum is greater than the target, move the right --.
    8. Continue this process until all unique quadruples are found.

    Time Complexity: O(n^3) - The three nested loops result in a cubic time complexity.
    Space Complexity: O(n) - The space used to store the unique quadruples in the set.
    */
    vector<vector<int>> result2;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue; // skip duplicates for first element
        for (int j = i + 1; j < n; j++)
        {

            if (j > i + 1 && arr[j] == arr[j - 1])
                continue; // skip duplicates for second element
            int left = j + 1, right = n - 1;

            while (left < right)
            {
                long long sum = arr[i] + arr[j] + arr[left] + arr[right];

                if (sum == target)
                {
                    result2.push_back({arr[i], arr[j], arr[left], arr[right]});
                    left++;
                    right--;
                    while (left < right && arr[left] == arr[left - 1])
                        left++; // skip duplicates for third element
                    while (left < right && arr[right] == arr[right + 1])
                        right--; // skip duplicates for fourth element
                }
                else if (sum < target)
                    left++;
                else
                    right--;
            }
        }
    }
    // print the unique quadruples
    cout << "The Unique Quadruples are: " << endl;
    for (auto quadruple : result2)
    {
        cout << "[";
        for (int i = 0; i < quadruple.size(); i++)
        {
            cout << quadruple[i];
            if (i != quadruple.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    return 0;
}