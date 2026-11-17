
#include <iostream>
#include <string>
using namespace std;

int main() {

    string s1,s2;

    cout << "Enter 1st string: ";
    cin >> s1;

    cout << "Enter 2nd string: ";
    cin >> s2;


    int n = s1.length();
    int m = s1.length();

    /* Problem: Alternate Merge Two Strings */

    /** Algorithm:
     * 1. Take two strings as input.
     * 2. Initialize an empty string to store the result.
     * 3. Take two pointer i and j. 
     * 4. Iterate i from 0 to length of first string and j from 0 to length of second string.
     * 5. Append characters: from 1st string first and then from 2nd string to the result string.
     * 6. If any char present in 1st string add simply in result string(s3), Same as for 2nd string(if any char present in 2ns string add simply in result string(s3)).
     * 7. Return or print the result string.
     * 
    */

    int i = 0,j=0;
    string s3;
    while (i<n && j<m)
    {
       s3 += s1[i];
       s3 += s2[i];

       i++,j++;
    }
    //If remaining characters in 1st string
    while (i<n)
    {
        s3 += s1[i];
        i++;
    }
    //If remaining characters in 2nd string
    while (j<m)
    {
        s3 += s2[j];
        j++;
    }

    cout << "Merged String: " << s3 << endl;
    
    return 0;
}
