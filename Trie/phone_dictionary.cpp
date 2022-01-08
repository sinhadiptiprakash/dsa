#include <bits/stdc++.h>
using namespace std;
struct TrieNode
{
    TrieNode *next[26];
    int freq;
    TrieNode()
    {
        freq = 0;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
};
void insert(TrieNode *root, string word)
{
    TrieNode *p = root;
    for (int i = 0; i < word.size(); i++)
    {
        int index = word[i] - 'a';
        if (!p->next[index])
            p->next[index] = new TrieNode();
        p = p->next[index];
    }
    p->freq++;
}
int search(TrieNode *root, string word)
{
    TrieNode *p = root;
    for (int i = 0; i < word.size(); i++)
    {
        int index = word[i] - 'a';
        if (!p->next[index])
            return 0;
        p = p->next[index];
    }
    return p->freq;
}
void dfs(TrieNode *root, string word, vector<string> &res)
{
    if (!root)
        return;
    if (root->freq > 0)
        res.push_back(word);
    for (int i = 0; i < 26; i++)
    {
        if (root->next[i])
            dfs(root->next[i], word + (char)(i + 'a'), res);
    }
}

vector<string> getMatches(TrieNode *root, string prefix)
{
    vector<string> res;
    TrieNode *p = root;
    for (char c : prefix)
    {
        if (p->next[c - 'a'])
            p = p->next[c - 'a'];
        else
        {
            res.push_back("0");
            return res;
        }
    }
    dfs(p, prefix, res);
    return res;
}
vector<vector<string>> phoneDictionary(vector<string> &words, string prefix)
{
    TrieNode *root = new TrieNode();
    for (string word : words)
        insert(root, word);
    vector<vector<string>> res;
    string temp = "";
    for (char c : prefix)
    {
        temp.push_back(c);
        vector<string> temp_res = getMatches(root, temp);
        res.push_back(temp_res);
    }
    return res;
}
int main()
{
    vector<string> words = {"geeikistest", "geeksforgeeks",
                            "geeksfortest"};
    vector<vector<string>> res = phoneDictionary(words, "geeips");
    for (vector<string> temp : res)
    {
        for (string s : temp)
            cout << s << " ";
        cout << endl;
    }
    return 0;
}