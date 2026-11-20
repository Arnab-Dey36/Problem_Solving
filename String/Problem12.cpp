
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

    int n,k;
    cout << "Enter Size of Array: ";
    cin >> n;
    
    cout << "Enter the value of k: ";
    cin >> k;
    vector<int> arr(n);
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
   


  /*Problem:Max Consecutive Ones III OR Max Consecutive 1's with K Flips
  
  Explanation: Given a binary array 'nums' and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's. Matlab, ek binary array 'nums' aur ek integer k diya gaya hai, aapko maximum number of consecutive 1's return karna hai agar aap at most k 0's ko flip kar sakte hain.

        Example 1: Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
                   Output: 6
  */
    
    /**Alogorithm:
     * Initialize left = 0, right = 0, zero = 0, and maxLen = 0.
     * Traverse the array using the right pointer.
     * If nums[right] == 0, increment zero means count of zeros in the current window.
     * If zero > k, shrink(delete zero from left side in the window) the window:
                - Check if nums[left] == 0.
                - If yes, decrement zero.
                - Increment left.
     * If zero <= k, calculate the current window length:
                - currentLen = right - left + 1.
                - update maxLen = max(maxLen, currentLen).
                - increment right.
     * Return maxLen.
     * Time Complexity: O(n) where n is the size of the array.And Space Complexity: O(1) as we are using constant space.
    */

    int left = 0, right = 0, zero = 0, maxLen = 0;
    while (right < n) {
        if (arr[right] == 0) {
            zero++;
        }
        while (zero > k) {
            if (arr[left] == 0) {
                zero--;
            }
            left++;
        }
        // if (zero <= k) {
        //     maxLen = max(maxLen, right - left + 1);
        // }

        maxLen = max(maxLen, right - left + 1);

        right++;
    }
    cout<<maxLen;
 
    return 0;
}
