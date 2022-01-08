#include <bits/stdc++.h>
using namespace std;

class Trie
{
public:
    bool freq;
    Trie *childrens[2];
};
Trie *create_trie_node()
{
    Trie *root = new Trie();
    root->freq = 0;
    for (int i = 0; i < 2; i++)
    {
        root->childrens[i] = NULL;
    }
    return root;
}
void insert(Trie *root, const vector<int> &row)
{
    Trie *curent = root;
    for (int c : row)
    {
        if (!curent->childrens[c])
        {
            curent->childrens[c] = create_trie_node();
        }
        curent = curent->childrens[c];
    }
    curent->freq = 1;
}
bool search(Trie *root, const vector<int> &row)
{
    Trie *curent = root;
    for (int c : row)
    {
        if (!curent->childrens[c])
            return false;
        curent = curent->childrens[c];
    }
    if (curent->freq == 1)
    {
        curent->freq = 0;
        return true;
    }
    return curent->freq;
}
vector<vector<int>> unique_rows(const vector<vector<int>> &matrix)
{
    int m = matrix.size();
    Trie *root = create_trie_node();
    for (int i = 0; i < m; i++)
    {
        insert(root, matrix[i]);
    }
    vector<vector<int>> res;
    for (int i = 0; i < m; i++)
    {
        if (search(root, matrix[i]))
            res.push_back(matrix[i]);
    }
    return res;
}
int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << endl;
    auto res = unique_rows(matrix);
    for (auto it : res)
    {
        for (int i : it)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}