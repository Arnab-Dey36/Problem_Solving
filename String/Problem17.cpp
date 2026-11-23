
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{

    string s;
    string k;
    cout << "Enter String: ";
    cin >> s;

    cout << "Enter the value of k: ";
    cin >> k;

    /*Problem: String Matching or Find the Index of the First Occurrence in a String(Leetcode 28)
     *      Explanation: Given a string s and a pattern p, find the first occurrence of p in s.
     * Example 1: Input: s = "hello", p = "ll"
     *            Output: 2
     * Explanation: The first occurrence of "ll" in "hello" is at index 2.
     * Example 2: Input: s = "onionionson", p = "onions"
     *           Output: 3
     * Explanation: The first occurrence of "onions" in "onionionson" is at index 3.
    */

    /**Brute Force Approach
     * 1. Use two pointers first and second, one for the string s and one for the pattern p.
     * 2. For each position, compare the characters of s and p one by one.i.e, s[first] == p[second]. If they match, move both pointers forward. If they don't match, reset the second pointer to 0 and move the first pointer to the next position.
     * 3. If all characters match, return the starting index.
     * Time Complexity: O(n*m), where n is the length of the string s and m is the length of the pattern p.
     * Space Complexity: O(1)
    */

    
    int n = s.length();
    int m = k.length();

    for (int i = 0; i <= n - m; i++)
    {
        int second = 0, first = i;
        // Comparing the characters of s and k one by one
        while (second < m)
        {
            // if the characters match, move both pointers forward
            if (s[first] == k[second])
            {
                first++;
                second++;
            }
            // if the characters don't match, reset the second pointer to 0 and move the first pointer to the next position
            else
            {
                // break;
                first++;
                second = 0;
            }
        }
        // if all characters match, return the first occurrence
        if (second == m)
        {
            cout << "The first occurrence of the pattern is at index: " << first - second << endl;
            return 0;
        }
    }

    cout << "Pattern not found in the string." << endl;

    /** OPtimal Approach: KMP Algorithm 
     * Create a Lps array for the second String(substring) and Initialize the lps array with 0. 
     * Use two pointers first and second, one for the string s and one for the substring p.
     * For each position, compare the characters of s and p one by one.i.e, s[first] == p[second]. If they match, move both pointers forward. If they don't match, then see the lps array to find the next position of the second pointer. 
     * How to find the next position of the second pointer? -->Jaha mismatch hua hai, uske pehle ke lps value ko dekho, aur us value ke corresponding index pe second pointer ko move karo.
     * If all characters match, return the starting index.
     * Time Complexity: O(n+m), where n is the length of the string s and m is the length of the pattern p.
     * Space Complexity: O(m), where m is the length of the pattern p.
    */

    // create a lps array for the second string (substring) and initialize it with 0
    vector<int> lps(m, 0);
    int pre = 0;
    int suff = 1;

    while (suff < m) {
        // Compare characters at pre and suff 
        if (k[pre] == k[suff]) { // If they match, increment pre and set lps[suff] = pre 
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

    // Now use the lps array to find the first occurrence of the pattern in the string
    int first = 0;
    int second = 0;
    while (first < n) {
        // Compare characters at first and second 
        if (s[first] == k[second]) { // If they match, increment both pointers
            first++;
            second++;
        } else {
            // If they don't match, check if second > 0
            if (second > 0) {
                second = lps[second - 1];
            } else {
                // If second == 0, increment first
                first++;
            }
        }
        // If all characters match, return the starting index
        if (second == m) {
            cout << "The first occurrence of the pattern is at index: " << first - second << endl;
            return 0;
        }
    }
    cout << "Pattern not found in the string." << endl;
    return 0;
}
