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
    Trie *root = new Trie();
    root->freq = 0;
    for (int i = 0; i < 26; i++)
    {
        root->childrens[i] = NULL;
    }
    return root;
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
void dfs(Trie *root, char prefix[], int index)
{
    if (!root)
        return;
    if (root->freq == 1)
    {
        prefix[index] = '\0';
        cout << prefix << ' ';
        return;
    }
    for (int i = 0; i < 26; i++)
    {
        if (root->childrens[i])
        {
            prefix[index] = i + 'a';
            dfs(root->childrens[i], prefix, index + 1);
        }
    }
}
void search(Trie *root, string word)
{
    char prefix[100];
    int index = 0;
    bool flag = 0;
    Trie *curent = root;
    for (char c : word)
    {
        if (!curent->childrens[c - 'a'])
        {
            cout << '0' << endl;
            return;
        }
        prefix[index++] = c;
        flag = 1;
        curent = curent->childrens[c - 'a'];
    }
    if (!flag)
        cout << '0' << endl;
    else
        dfs(curent, prefix, index);
    cout << endl;
}
int main()
{
    auto root = create_trie_node();
    int n;
    cin >> n;
    vector<string> contact(n);
    for (int i = 0; i < n; i++)
    {
        cin >> contact[i];
        insert(root, contact[i]);
    }
    string s;
    cin >> s;
    string prefix = "";
    for (char c : s)
    {
        prefix.push_back(c);
        search(root, prefix);
    }
    return 0;
}