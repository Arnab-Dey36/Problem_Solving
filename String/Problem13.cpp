
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {

    string s;
    int k;
    cout << "Enter String: ";
    cin >> s;
    
    cout << "Enter the value of k: ";
    cin >> k;
    
   


  /*Problem:Longest Substring with K Uniques

  Explanation:You are given a string s consisting only lowercase alphabets and an integer k. Your task is to find the length of the longest substring that contains exactly k distinct characters.

    Note : If no such substring exists, return -1. 

        Example 1: Input: s = "aabacbebebe", k = 3
                   Output: 7
  */
    
  /**Algorithm:
   
   * Initialize left = 0, right = 0, maxLen = -1 and an unordered map to store character frequencies.
   * Traverse the String s using the right pointer.
   * Add the current character s[right] into the map and increase its frequency.
   * If the number of distinct characters (mp.size()>k) is greater than k:
            - Remove the character at s[left] (left side se delete karo) from the map.
            - Decrease its frequency.
            - If its frequency becomes 0, erase it from the map.
            - Increment left.
   * If the number of distinct characters (mp.size() == k) is equal to k:
            - Calculate the current window length: currentLen = right - left + 1.
            - Update maxLen = max(maxLen, currentLen).
            - Increment right.
   * Return maxLen.If not found return -1.
   
   * Time Complexity: O(n) where n is the size of the string.And Space Complexity: O(k) as we are using a map to store character frequencies.
   */

   int left = 0, maxLen = -1,right = 0;
   unordered_map<char, int> mp;

    while (right < s.size()) {
        // Add the current character to the map and increase its frequency
        mp[s[right]]++;

        // If the number of distinct characters is greater than k, shrink the window from the left
        while (mp.size() > k) {
            // Remove the character at s[left] from the map.
            mp[s[left]]--;

            // If its frequency becomes 0, erase it from the map.
            if (mp[s[left]] == 0) {
                mp.erase(s[left]);
            }
            left++;
        }
        // If the number of distinct characters is equal to k, update maxLen
        if (mp.size() == k) {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
    }

    cout << maxLen << endl;
    return 0;
}
