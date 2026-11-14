#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string s;

    cout << "Enter Your String: ";
    getline(cin,s);



   /*Problem: Sort The Word for lower case only*/

   //using inbuilt function
   sort(s.begin(),s.end());
   cout<<s;

   /**Algorithm:
    * 1. Create a count variable to store the count or Frequency of each character in the string.
    * 2. Initialy size of count variable is 26 and initially all values are 0. 
    * 3. traverse the string,store the frequency of each character in the count variable.
    * 4. Now traverse the count variable and print the character according to their frequency.
    * Time Complexity: O(n) and Space Complexity: O(1)
    */
   int n = s.length();
    int count[26] = {0};

    for(int i = 0;i<n;i++){
        int index = s[i] - 'a';
        count[index]++;
    }
   //now traverse the count variable and print the character according to their frequency.
    for(int i = 0;i<26;i++){
        for(int j = 0;j<count[i];j++){
            char ch = 'a' + i;
            cout<<ch;
        }
    }

    return 0;
}