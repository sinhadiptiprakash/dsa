#include <bits/stdc++.h>
using namespace std;

struct Trie
{
    int freq;
    Trie *childrens[26];
};
Trie *create_trie_node()
{
    Trie *root = new Trie();
    root->freq = 0;
    for (int i = 0; i < 26; i++)
        root->childrens[i] = NULL;
    return root;
}
void insert(Trie *root, string word)
{
    Trie *curent = root;
    for (char c : word)
    {
        if (!curent->childrens[c - 'a'])
            curent->childrens[c - 'a'] = create_trie_node();
        curent = curent->childrens[c - 'a'];
    }
    curent->freq += 1;
}
int search(Trie *root, string word)
{
    Trie *curent = root;
    for (char c : word)
    {
        if (!curent->childrens[c - 'a'])
            return 0;
        curent = curent->childrens[c - 'a'];
    }
    return curent->freq;
}
void delete_single_instance(Trie *root, string word)
{
    Trie *curent = root;
    for (char c : word)
    {
        if (!curent->childrens[c - 'a'])
            return;
        curent = curent->childrens[c - 'a'];
    }
    curent->freq -= 1;
}
void delete_all_instances(Trie *root, string word)
{
    Trie *curent = root;
    for (char c : word)
    {
        if (!curent->childrens[c - 'a'])
            return;
        curent = curent->childrens[c - 'a'];
    }
    curent->freq = 0;
}
int main()
{
    auto root = create_trie_node();
    insert(root, "hello");
    insert(root, "world");
    insert(root, "hell");
    insert(root, "hell");
    insert(root, "help");
    insert(root, "hello");
    cout << search(root, "hell") << endl;
    delete_single_instance(root, "helloooo");
    cout << search(root, "hell") << endl;
    return 0;
}