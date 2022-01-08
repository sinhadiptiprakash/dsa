#include <bits/stdc++.h>
using namespace std;
class Trie
{
public:
    int freq;
    Trie *childrens[26];
};
Trie *create_trie_node()
{
    Trie *newNode = new Trie;
    // we make every node's frequency as initially 1 to identify the unique prefix
    newNode->freq = 1;
    for (int i = 0; i < 26; i++)
        newNode->childrens[i] = NULL;
    return newNode;
}
void insert(Trie *root, string word)
{
    Trie *curent = root;
    for (char c : word)
    {
        if (!curent->childrens[c - 'a'])
            curent->childrens[c - 'a'] = create_trie_node();
        else
            (curent->childrens[c - 'a']->freq)++;
        curent = curent->childrens[c - 'a'];
    }
}
void dfs(Trie *root, string temp, vector<string> &res)
{
    if (!root)
        return;
    if (root->freq == 1)
    {
        res.push_back(temp);
        return;
    }
    for (char c = 'a'; c <= 'z'; c++)
    {
        dfs(root->childrens[c - 'a'], temp + c, res);
    }
}
vector<string> shortestUniquePrefix(const vector<string> &words)
{
    Trie *root = create_trie_node();
    root->freq = 0;
    for (auto word : words)
        insert(root, word);
    vector<string> res;
    dfs(root, "", res);
    return res;
}
int main()
{
    Trie *root = create_trie_node();
    // as root is not pointing to any character of any of the strings of the input we shoult make
    // the frequency as 0
    root->freq = 0;
    vector<string> arr = {"geeksgeeks", "geeksquiz", "geeksforgeeks"};
    // below is the special case where there may be some words which are prefix of some other words in the list
    // and for this special case the above algo does'nt output the unique prefix
    // for those words which are preix of other words in the list
    vector<string> arr2 = {"zebra", "dog", "duck", "dove"};
    vector<string> arr3 = {"dipti", "dipu", "dog", "doctor", "puntu", "punpun", "bebu"};
    auto res = shortestUniquePrefix(arr3);
    for (auto str : res)
        cout << str << endl;
    return 0;
}