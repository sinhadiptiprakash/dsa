#include<bits/stdc++.h>
using namespace std;
//method 1 slowest but accepted
string reverseWords(string s)
{
    int n = s.length();
    stringstream stream(s);
    string res = "", temp;
    while (stream >> temp)
    {
        res = temp + res;
        res = ' ' + res;
    }
    return res.substr(1);
}
//method 2
string reverseWords(string s)
{
    int n = s.length();
    string result = "", word = "";
    int i = 0;
    while (i < n)
    {
        //skip spaces
        while (i < n && s[i] == ' ')
            i++;

        //collect word
        word = "";
        while (i < n && s[i] != ' ')
        {
            word += s[i];
            i++;
        }
        // append word in  front
        if (!result.length())
            result = word;
        else if (word.length())
            result = word + ' ' + result;
    }

    return result;
}
int main(){
    return 0;
}