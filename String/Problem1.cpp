#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string s;

    cout << "Enter Your String: ";
    getline(cin,s);

    

    /*Problem: Reverse a String  */

    /**Algorithm:
     * 1. Take input string from user.
     * 2. Use reverse function to reverse the string. 
     * Time Complexity: O(n), where n is the length of the string. and Space Complexity: O(1) as we are not using any extra space.
    */
    reverse(s.begin(), s.end());
    cout<<s;

    /**Optimization:Using Two Pointer Approach
     * 1. Initialize two pointers, one at the beginning of the string and the other at the end.
     * 2. Swap the characters at the two pointers.
     * 3. Move the pointers towards each other until they meet in the middle.
     * 4. Continue until the pointers meet or cross each other.
     * Time Complexity: O(n/2) = O(n), where n is the length of the string. and Space Complexity: O(1) as we are not using any extra space.
    */

    int st = 0,end = s.size()-1;
    while (st<=end)
    {
        swap(s[st],s[end]);
        st++,end--;
    }
    cout<<s;
   
}