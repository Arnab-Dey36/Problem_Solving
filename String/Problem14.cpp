
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    string s;
    int k;
    cout << "Enter String: ";
    cin >> s;
    
    cout << "Enter the value of k: ";
    cin >> k;
    
   


  /*Problem: Longest Repeating Character Replacement

  Explanation:You are given a string s and an integer k. You can choose any character of the string and change 
  it to any other uppercase English character. You can perform this operation at most k times.Return the length of the 
  longest substring containing the same letter you can get after performing the above operations. 

        Example 1: Input: s = "AABABBA", k = 1
                   Output: 4
            Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
                    The substring "BBBB" has the longest repeating letters, which is 4.
  */
    
  /**Approach: Sliding Window
   * 1. Initialize left = 0, maxFreq = 0, and maxLen = 0.
   * 2. Create a frequency array of size 26 and initialize it with zero.
   * 3. Run a loop using the right pointer from 0 to s.size()-1.
   * 4. Add the current character s[right] to the frequency array.
   * 5. Update maxFreq with the maximum frequency of a character. like that: maxFreq = max(maxFreq, freq[s[right] - 'A']).
   * 6. Calculate the number of characters that need replacement:
                          - replacements = windowSize - maxFreq

   * 7. If replacements are greater than k, shrink the window by moving left forward and decrease the frequency of s[left].
   * 8. Update maxLen with the maximum length of the window.And return maxLen as the result.
   * 
   * Time Complexity: O(n), where n is the length of the string s. And Space Complexity: O(1), as the frequency array has a fixed size of 26.
   */

   int left = 0 ,maxFreq = 0,maxLen = 0;
   
   // Create a frequency array of size 26 and initialize it with zero.
   vector<int>freq(26,0);

   for(int right = 0;right<s.size();right++){
        freq[s[right] - 'A']++; // Increase the frequency of the current character in the frequency array.

        maxFreq = max(maxFreq,freq[s[right]-'A']); // Update maxFreq with the maximum frequency of a character.

        int windowSize = right - left + 1; // Calculate the size of the current window.
    
        // If the number of characters that need replacement is greater than k, shrink the window by moving left forward.
        if(windowSize - maxFreq >k){ 
            freq[s[left] - 'A']--;
            left++;
        }
        // Update maxLen with the maximum length of the window.
        maxLen = max(maxLen,right - left + 1);
   }

   cout<<maxLen;
  
    return 0;
}
