#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string s;

    cout << "Enter Your String: ";
    getline(cin,s);



   /*Problem: Sort The Word for Both lower case And Uppercase*/

   //using inbuilt function-->Time Complexity=O(nlogn) & Space = O(1)
//    sort(s.begin(),s.end());
//    cout<<s;

   /**Algorithm:
    * Create a count array of size 52 to store the frequency of uppercase and lowercase characters.
    * Initially, all elements of the count array are 0.
    * Traverse the string and calculate the index of each character:
                - For uppercase (A-Z): index = s[i] - 'A'
                - For lowercase (a-z): index = s[i] - 'a' + 26
    * Increase the frequency of the corresponding index.
    * Traverse the count array:
                - First print uppercase characters (A-Z).
                - Then print lowercase characters (a-z).
    * Print each character according to its frequency.
    * Time Complexity: O(n) and Space Complexity: O(1)
    */
   int n = s.length();
   int count[52] = {0};
    // Store frequency
    for(int i=0;i<n;i++){
        int index;
        if(s[i]>='A' && s[i]<='Z'){ // For Uppercase character
            index = s[i]-'A';
        }
        else
        {
            index = s[i]-'a'+26; // For lowercase character, we add 26 to the index to differentiate them from uppercase character
        
        }
        count[index]++;
    }

    // Print sorted characters
    for (int i = 0; i < 52; i++) {

        for (int j = 0; j < count[i]; j++) {

            char ch;

            if (i < 26) {
                // For uppercase character
                ch = 'A' + i;
            }
            else {
                // For lowercase character
                ch = 'a' + (i - 26);
            }

            cout << ch;
        }
    }
    return 0;
}