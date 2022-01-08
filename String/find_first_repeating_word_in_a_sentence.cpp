#include <bits/stdc++.h>
using namespace std;
//approach is to use a map<word,first position of that word in the sentence and count>
string first_repeating_word(string sentence)
{
    unordered_map<string, pair<int, int>> mp;
    int n = sentence.length();
    string word;
    int index = 0, temp_index, temp_cnt;
    for (int i = 0; i <= n; i++)
    {
        if (sentence[i] == ' ' || i == n)
        {
            //we store the word in the mp
            //if the word already there in mp we store the curent word with the stored index to maintain the order
            //also increasing the count
            if (mp.find(word) != mp.end())
            {
                temp_cnt = mp[word].second;
                temp_index = mp[word].first;
                mp[word] = {temp_index, temp_cnt + 1};
            }
            else
                mp[word] = {index, 1};
            //next word index will start from i+1 after getting space at i
            index = i + 1;
            //make the sentence empty to contain the next word
            word = "";
        }
        else
            word.push_back(sentence[i]);
    }
    //now word will store the result index will store the index which is minimum
    word = "No Repetition";
    for (auto it : mp)
    {
        if (it.second.second > 1 && it.second.first < index)
        {
            index = it.second.first;
            word = it.first;
        }
    }
    return word;
}
//we can do it better by a simple observation: whenever we see a word is already in the set we return the word
//thus no need to store count or index
string first_repeating_word2(string sentence)
{
    unordered_set<string> set;
    int n = sentence.length();
    string word;
    for (int i = 0; i <= n; i++)
    {
        if (sentence[i] == ' ' || i == n)
        {
            //we store the word in the mp
            //if the word already there in mp we return the word
            if (set.find(word) != set.end())
            {
                return word;
            }
            else
            { //else store the word in set
                set.insert(word);
            }
            //make the sentence empty to contain the next word
            word = "";
        }
        else
            word.push_back(sentence[i]);
    }
    //if there is no repettion return string "no repetition"
    return "No Repetition";
} //time complexity is same as the above bt in best or average case it is optimized and space is also optimized
//time complexity is O(S) where S is total no. of characters in sentences space complexity is O(S)
//because in worst case we have to traverse the whole sentence and have to store all the words
int main()
{
    string sentence;
    getline(cin, sentence);
    cout << first_repeating_word2(sentence) << endl;
    return 0;
}