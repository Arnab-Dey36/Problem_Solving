#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string s;

    cout << "Enter Your String: ";
    getline(cin,s);

    

    /*Problem: Check Palindrome */

    /**Algorithm:
     * 1. Initialize two pointers, one at the beginning of the string and the other at the end.
     * 2. Compare the characters at the two pointers.
     * 3. If the characters are not equal, the string is not a palindrome.
     * 4. Move the pointers towards each other until they meet in the middle.
     * 5. Otherwise, it is a palindrome.
     * Time Complexity: O(n/2) = O(n), where n is the length of the string. and Space Complexity: O(1) as we are not using any extra space.
    */
   int st = 0,end = s.size()-1;
   while (st<=end)
   {
    if(s[st] != s[end]){
        cout<<"Not Palindrome";
        return 0;
    }
    st++,end--;
   }
   cout<<"Palindrome";
   return 0;
}