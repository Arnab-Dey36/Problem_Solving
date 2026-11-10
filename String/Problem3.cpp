#include <iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    string s;

    cout << "Enter Your String: ";
    getline(cin,s);



    /*Problem: Sorting the Sentence 
        Example: Input: "is2 sentence4 This1 a3"
                 Output: "This is a sentence"
        COnditions:
        1. The number in the word will tell you the position of the word in the final sentence.
        2. The final sentence should be in the order of the numbers in the words.
    */

    /**Algorithm:
     * 1. Take the input string from the user. like "is2 sentence4 This1 a3"
     * 2. Traverse the string and add the each letter of the word in a temporary string(temp) until you find a space or a number.
     * 3. when you see a space, you can consider that this is a one word.and calculate the position of the word in the final sentence.
     *                   - position = temp[temp.size()-1] - '0'; // this will give you the position of the word in the final sentence.
     *                   - '0' is used to convert the character to integer.
     * 4. Now, you can add this word in the final sentence at the position after removing the number from the word.and after successfully adding the word in the final sentence, you can clear the temporary string(temp) and continue the process.
     * 5. If not see space then simply add the letter to the temporary string(temp) and increment the index.
     * 6. Repeat the process until you reach the end of the string.
     * 7. If still there is a word left in the temporary string(temp) then add it to the final sentence.
    */
   vector<string> ans(10);

    int count = 0, index = 0;
    string temp;

    while (index < s.size())
    {
        // If space is found
        if (s[index] == ' ')
        {
            int pos = temp[temp.size() - 1] - '0';

            temp.pop_back();

            ans[pos] = temp;

            temp.clear();
            count++;
            index++;
        }
        //if space not found simply add it
        else
        {
            temp += s[index];
            index++;
        }
    }

    // Process the last word
    if (!temp.empty())
    {
        int pos = temp[temp.size() - 1] - '0';

        temp.pop_back();

        ans[pos] = temp;
        temp.clear();
        count++;
    }

    // Print the sorted sentence
   
    for (int i = 1; i <= count; i++)
    {
        temp += ans[i];
        temp += " ";
    }

    if (!temp.empty())
        temp.pop_back();

    cout << temp;
   
   return 0;
}