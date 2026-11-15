
#include <iostream>
#include <string>
using namespace std;

int main() {

    string s;

    cout << "Enter string: ";
    cin >> s;


    int n = s.length();

    /* Problem: Binary Substrings with Corners as 1 */

    /** Algorithm:
     * Traverse the string and Count all the 1 present in given string.
     * Now, choose any of 2 from the count of 1 present in the string.
     * The number of ways to choose 2 items from n items is count*(count-1)/2.
     * Time Complexity: O(n) and Space Complexity: O(1)
     
    */
    //edge case: if n, 2 se small hai return 0 kar do ans possible nahi hai because 2 corners chahiye humein.
    if(n<2){
        cout<<0;
        return 0;
    }

    long count = 0;
    for(int i = 0;i<n;i++){
        if(s[i] == '1')
        count++;
    }
    count =  count*(count-1)/2;
    cout<<count;
    
    return 0;
}
