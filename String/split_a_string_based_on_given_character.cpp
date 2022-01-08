#include <bits/stdc++.h>
using namespace std;
//naive appraoch
vector<string> split_string(string sentence, char c)
{
    vector<string> result;
    int n = sentence.length();
    string word;
    for (int i = 0; i <= n; i++)
    {
        if (sentence[i] == c || i == n)
        {
            result.push_back(word);
            //make the sentence empty to contain the next word
            word = "";
        }
        else
            word.push_back(sentence[i]);
    }
    return result;
}
//using getline function
vector<string> split_string_using_getline(string sentence, char c)
{
    vector<string> res;
    string T;
    stringstream X(sentence);
    while (getline(X, T, c))
    {
        res.push_back(T);
    }
    return res;
}
int main()
{
    string sentence;
    getline(cin, sentence);
    auto res = split_string_using_getline(sentence, ' ');
    for (auto it : res)
    {
        cout << it << endl;
    }
    return 0;
}