
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    string s;
    int k;
    cout << "Enter String: ";
    cin >> s;

   


  /*Problem: Longest Prefix Suffix
        Example 1:  Input: s = "aabcdaabc"
                    Output: 4
                    Explanation: The string "aabc" is the longest prefix and suffix.
  */
    
  /** Algorithm: KMP (Knuth-Morris-Pratt) Algorithm and Two Pointer Approach
   * 1. Create a 'lps' (longest proper prefix which is also suffix) array of size n.
   * 2. Initialize lps[0] = 0.
   * 3. Use two pointers, pre and suff, to traverse the string. Start with pre = 0 and suff = 1.
   * 4. While suff < n, compare s[pre] and s[suff]:
   *    - If they are equal, increment pre and set lps[suff] = pre.Then increment suff.
   *    - If they are not equal, and pre > 0, set pre = lps[pre - 1].
   *    - If they are not equal and pre == 0, set lps[suff] = 0 and increment suff.
   * 5. The value of lps[n - 1] will give the length of the longest prefix which is also a suffix.
   *  Time Complexity: O(n), where n is the length of the string s. And Space Complexity: O(n), as we are using an additional array of size n.
   * 
   * NOTE: pre = lps[pre - 1] --->iska matlab hai ki agar pre aur suff ke characters match nahi karte hain pre ke sath , toh hum pre ko lps[pre - 1] pe set karenge, jisse hum pre ke previous character pe jo value hai uss index pe le jaayenge aur phir se compare karenge, agar match karte hain toh pre ko increment karenge aur lps[suff] = pre + 1 set karenge, aur suff ko increment karenge. Agar match nahi karte hain toh phir se pre ko lps[pre - 1] pe set karenge aur phir se compare karenge.
   */
  int n = s.length();
  vector<int> lps(n, 0);
  int pre = 0;
  int suff = 1;

    while (suff < n) {
        // Compare characters at pre and suff 
        if (s[pre] == s[suff]) { // If they match, increment pre and set lps[suff] = pre 
            pre++;
            lps[suff] = pre;
            suff++;
        } else {
            // If they don't match, check if pre > 0
            if (pre > 0) {
                pre = lps[pre - 1];
            } else {
                // If pre == 0, set lps[suff] = 0 and increment suff
                lps[suff] = 0;
                suff++;
            }
        }
    }
    cout << "The length of the longest prefix which is also a suffix is: " << lps[n - 1] << endl;
    return 0;
}
