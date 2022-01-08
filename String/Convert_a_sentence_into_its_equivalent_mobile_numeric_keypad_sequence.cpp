#include <bits/stdc++.h>
using namespace std;
string convert_sentence_to_numeric_sequence(string sentence)
{
    //one by one create all the alphabets statically as numeric sequnces and store them into a vector
    vector<string> alphabets(26);
    alphabets = {
        "2", "22", "222",         //for a,b,c
        "3", "33", "333",         //def
        "4", "44", "444",         //for ghi
        "5", "55", "555",         //for jkl
        "6", "66", "666",         //for mno
        "7", "77", "777", "7777", //for pqrs
        "8", "88", "888",         //for tuv
        "9", "99", "999", "9999"  //for wxyz
    };
    //now make the numeric string by replacing each character with its equivalent numeric sequence
    string result = "";
    for (char c : sentence)
    {
        //taking care of the space
        if (c == ' ')
            result += '0';
        else
            result += (alphabets[c - 'a']);
    }
    return result;
}
int main()
{
    string sentence;
    cin >> sentence;
    cout << convert_sentence_to_numeric_sequence(sentence) << endl;
    return 0;
}