
#include <iostream>
#include <string>
using namespace std;

int main() {

    string s1,s2;

    cout << "Enter 1st string: ";
    cin >> s1;

    


    int n = s1.length();
    

    /* Problem: Convert String to Lowercase */

    /** Algorithm:
        1. Initialize an empty string c to store the converted string.

        2. Traverse the given string s from index 0 to s.size()-1.

        3. Check whether the current character is an uppercase alphabet (between 'A' and 'Z').

        4. If it is uppercase, convert it into lowercase using the formula:
                - lowercase = 'a' + s[i] - 'A'

        5. Append the converted character to string c.

        6. Otherwise, append the original character to c without any changes.

        7. Repeat the process until all characters are traversed.

        8. Finally, return the string c.
        Time Complexity: O(n) and Space Complexity: O(n)
    */

   string c;
   for(int i = 0;i<n;i++){
    if(s1[i]>='A' && s1[i]<='Z'){
        c += 'a' + s1[i] -'A';
    }
    else{
        c += s1[i];
    }
   }

   cout<<"Converted String: "<<c;
    
    return 0;
}
