
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

    string s;
    cout << "Enter 1st string: ";
    cin >> s;

    


    int n = s.length();
    

    /* Problem: Length Of Longest Substring Without Repeating Characters */

    /** Brute Force Algorithm:
        1. Use two pointers, Initialize two pointers i = 0 and j = 0 and a variable maxLength = 0 to keep track of the maximum length of the substring without repeating characters.
        2. use a hash,initially hash[256] = {0} to keep track of the characters in the current substring.
        3. Iterate through the string using the second pointer j.
        4. If the character at index j is not present in the hash, add it to the hash and update maxLength if necessary like maxLength = max(maxLength, j - i + 1).
        5. If the character at index j is already present in the hash, move the first pointer i to the right until the character at index j is no longer in the substring.
        6. Repeat steps 3-5 until j reaches the end of the string.
        Time Complexity: O(n^2) where n is the length of the string.
        Space Complexity: O(1) as the hash size is constant (256).
    */
    // int maxLength = 0;
    // for (int i = 0; i < n; i++) {
    //     bool hash[256] = {0};
    //     for (int j = i; j < n; j++) {
    //         if (hash[s[j]] == 1) {
    //             break;
    //         } else {
    //             hash[s[j]] = 1;
    //             maxLength = max(maxLength, j - i + 1);
    //         }
    //     }
    // }

    // cout << "Length of the longest substring without repeating characters: " << maxLength << endl;

    /** Sliding Window Algorithm:
       NOTE: 1.Jab Bhi Mere pass uniquie character ate rahenge toh main window ko expand karunga means pointer j ko aage badhao.
             2.Jab Bhi Mere pass duplicate character aayega to mai window ko shrink karunga means pointer i ko aage badhao.
             3.Jab bhi main window ko shrink karta hoon toh usme se character ko hash se delete karna padega.

        1. Use two pointers, Initialize two pointers i = 0 and j = 0 and a variable maxLength = 0 to keep track of the maximum length of the substring without repeating characters.
        2. Ek hash array use karo jiska size 256 hoga, aur initialize karo sabhi elements ko 0 se.
        3. Iterate karo string ke upar aur dekho agar character repeat nahi ho raha toh usko hash mein add karo means 1 bana do (ekbar dekh 
        liya us character ko) aur  maxLength ko update karo like maxLength = max(maxLength, j - i + 1).
        4. if the character is already present in the hash, toh window ko shrink karo means pointer i ko aage badhao,matlab delete karna hoga character ko hash se(Wapas 0 karna hoga).
        5. Repeat steps 3-4 until j reaches the end of the string.
        Time Complexity: O(n) where n is the length of the string.
    */
   int maxLength = 0;
   int first = 0,second = 0;
   vector<bool> hash(256,0); //count kar raha hai konsa chracter kitna bar aya hai. Agar koi character dubar aya toh usko chracter ko phele se delete karna hoga hash se.
   while (second < n) {
  
    while (hash[s[second]]) { // If the character is already present in the hash, shrink the window
        hash[s[first]] = 0; // Remove the character from the hash
        first++;
    }
    hash[s[second]] = 1; // Add the character to the hash
    maxLength = max(maxLength, second - first + 1); // Update maxLength
    second++; // Move the second pointer to the right
   }
   cout << "Length of the longest substring without repeating characters: " << maxLength << endl;

    return 0;
}
