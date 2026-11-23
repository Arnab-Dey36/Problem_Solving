
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{

    string str;
    cout << "Enter String: ";
    cin >> str;


    /* Problem: Minimum Insertions for Palindrome.
    Explain: Given a string s, the task is to find the minimum characters to be added at the front to make
     the string palindrome.
    */

    /**Algorithm: KMP (Knuth-Morris-Pratt) Algorithm
     * 1. Reverse the orginal string 
     * 2. At the end of the original string, append a special character (not present in the string) and then append the reversed string.
     * 3. Now, find the LPS (Longest Prefix Suffix) array of the new string.
     * 4. The last value of the LPS array will give us the length of the longest palindromic suffix of the original string.
     * 5. The minimum number of insertions required is the difference between the length of the original string and the length of the longest palindromic suffix.
     *          i.e. minInsertions = originalStringLength - longestPalindromicSuffixLength
     * Time Complexity: O(n), where n is the length of the string. And Space Complexity: O(n), where n is the length of the string.
    */
    
    //Reverse the original string
    string rev = str;
    reverse(rev.begin(), rev.end());

    int oldLength = str.length();
    //Append a special character and the reversed string to the original string
    // str += "$" ;
    // str += rev;
    string newStr = str + "$" + rev;

    // After appending the reversed string with special character, the new Length of the string 
    int newLength = newStr.length();

    // Create a LPS array of size newLength
    vector<int> lps(newLength, 0);
    int pre = 0,suff = 1;
    
    while (suff < newLength)
    {
        // Compare characters at pre and suff 
        if (newStr[pre] == newStr[suff]) // If they match, increment pre and set lps[suff] = pre 
        {
            pre++;
            lps[suff] = pre;
            suff++;
        }
        else
        {
            // If they don't match, check if pre > 0
            if (pre > 0)
            {
                pre = lps[pre - 1];
            }
            else
            {
                // If pre == 0, set lps[suff] = 0 and increment suff
                lps[suff] = 0;
                suff++;
            }
        }
    }

    cout << "The minimum number of insertions required to make the string palindrome is: " << oldLength - lps[newLength - 1] << endl;

    return 0;
}
