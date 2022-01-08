#include <bits/stdc++.h>
using namespace std;

class Trie
{
public:
    bool freq;
    Trie *childrens[26];
    vector<int> indexes;
};
Trie *create_trie_node()
{
    Trie *root = new Trie();
    root->freq = 0;
    for (int i = 0; i < 26; i++)
        root->childrens[i] = NULL;
    return root;
}
void insert(Trie *root, string word, int index)
{
    Trie *curent = root;
    for (char c : word)
    {
        if (!curent->childrens[c - 'a'])
            curent->childrens[c - 'a'] = create_trie_node();
        curent = curent->childrens[c - 'a'];
    }
    curent->freq = 1;
    curent->indexes.push_back(index);
}
vector<string> search(Trie *root, const vector<string> &dict, string word, vector<bool> &visited)
{
    vector<string> res;
    Trie *curent = root;
    for (char c : word)
    {
        if (!curent->childrens[c - 'a'])
            return {};
        curent = curent->childrens[c - 'a'];
    }
    if (curent->freq)
    {
        for (int i : curent->indexes)
        {
            res.push_back(dict[i]);
            visited[i] = true;
        }
    }
    return res;
}
vector<vector<string>> Anagrams(vector<string> &string_list)
{
    Trie *root = create_trie_node();
    vector<vector<string>> res;
    vector<string> temp = string_list;
    for (int i = 0; i < string_list.size(); i++)
    {
        sort(temp[i].begin(), temp[i].end());
        insert(root, temp[i], i);
    }
    vector<bool> visited(temp.size(), 0);
    for (int i = 0; i < temp.size(); i++)
    {
        if (!visited[i])
        {
            auto tmp = search(root, string_list, temp[i], visited);
            res.push_back(tmp);
        }
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    auto res = Anagrams(v);
    for (auto vec : res)
    {
        for (auto i : vec)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}