#include <bits/stdc++.h>
using namespace std;
class Solution
{
    class Trie
    {
    public:
        bool word_end;
        Trie *children[26];
    };

public:
    Trie *create_node()
    {
        Trie *new_node = new Trie();
        new_node->word_end = false;
        for (int i = 0; i < 26; i++)
        {
            new_node->children[i] = NULL;
        }
        return new_node;
    }
    void insert(Trie *root, string word)
    {
        Trie *curent = root;
        for (char c : word)
        {
            if (!curent->children[c - 'a'])
                curent->children[c - 'a'] = create_node();
            curent = curent->children[c - 'a'];
        }
        curent->word_end = true;
    }
    bool search(Trie *root, string word)
    {
        Trie *curent = root;
        for (char c : word)
        {
            if (!curent->children[c - 'a'])
                return false;
            curent = curent->children[c - 'a'];
        }
        return curent->word_end;
    }
    bool wordBreak(string s, vector<string> &dict)
    {
        if (dict.size() == 0)
            return false;
        Trie *root = create_node();
        for (string str : dict)
        {
            insert(root, str);
        }
        int n = s.size();
        bool t[n + 1];
        memset(t, false, sizeof(t));
        t[0] = true;
        // we split the string at every possible values of i
        for (int i = 1; i <= s.size(); i++)
        {
            // we check every solution of sub-problmes from j=0 to i-1 in bakcwards
            for (int j = i - 1; j >= 0; j--)
            {
                if (t[j])
                {
                    string str = s.substr(j, i - j);
                    auto it = search(root, str); // search for str in dictionary
                    // we the string is in the dictionary
                    if (it)
                    {
                        // and if the solution of subproblem from i to end is true then the t is true
                        t[i] = true;
                        break;
                    }
                }
            }
        }

        return t[n];
    }
};
int main()
{
    Solution sl;
    string s;
    int n;
    vector<string> dict;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        dict.push_back(s);
    }
    cin >> s;
    cout << sl.wordBreak(s, dict) << endl;
    return 0;
}