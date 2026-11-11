#include <iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    string s;

    cout << "Enter Your String: ";
    getline(cin,s);



    /*Problem: Remove All Occurrences of a Substring 
        Example:  s = "daabcbaabcbc", part = "abc"

        Conditions:Find the leftmost occurrence of the substring part and remove it from s. 
        Repeat this process until part does not occur in s.
    */

    /**Algorithm:
     * 1. Take the input string from the user. like "daabcbaabcbc"
     * 2. Take the input substring from the user. like "abc"
     * 3. Use the find() function to find the leftmost occurrence of the substring part in the string s.
     * 4. If the substring is found, use the erase() function to remove it from the string s.
     * 5. Repeat steps 3 and 4 until the substring is no longer found.
     * 6. Print the final string s.
     * Time Complexity: O(n*m) where n is the length of the string s and m is the length of the substring part.
     * Space Complexity: O(1) as we are not using any extra space except for the input string and substring.
     *
    */
    string part;
    cout << "Enter the substring to remove: ";
    getline(cin, part);

    
    while (s.length()>0 && s.find(part)< s.length()) {
        s.erase(s.find(part), part.length());
        
    }
    cout << "Final string: " << s << endl;
   
}