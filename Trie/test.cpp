#include <bits/stdc++.h>
using namespace std;
// as the strings contains only lowercase elglish alphabets 
#define MAX 26
// Maximum length of an input word
#define MAX_WORD_LEN 500

// Trie Node.
 class Trie
{
    public:
    Trie *child[MAX];
    int freq; // To store frequency
    vector<int> indexes;
};

// Function to create a new trie node.
 Trie *newTrieNode(void)
{
     Trie *newNode = new Trie;
    newNode->freq = 1;
    for (int i = 0; i < MAX; i++)
        newNode->child[i] = NULL;
    return newNode;
}

// Method to insert a new string into Trie
void insert(Trie *root, string word)
{
     Trie* curent = root;
    // Traversing over the length of given str.
    for (char c:word)
    {
        // Get index of child node from current character
        // in str.
        int index = c-'a';

        // Create a new child if not exist already
        if (!curent->child[index])
            curent->child[index] = newTrieNode();
        else
            (curent->child[index]->freq)++;

        // Move to the child
        curent = curent->child[index];
    }
}

// This function prints unique prefix for every word stored
// in Trie. Prefixes one by one are stored in prefix[].
// 'ind' is current index of prefix[]
void dfs(Trie *root, char prefix[],int ind)
{
    // Corner case
    if (!root)
        return;

    // Base case
    if (root->freq == 1)
    {
        prefix[ind] = '\0';
        cout << prefix << " ";
        return;
    }

    for (int i = 0; i < 26; i++)
    {
        if (root->child[i])
        {
            prefix[ind] = i+'a';
            dfs(root->child[i], prefix, ind + 1);
        }
    }
}

// Function to print all prefixes that uniquely
// represent all words in arr[0..n-1]
void find_prefixes(string arr[], int n)
{
    // Con a Trie of all words
    Trie *root = newTrieNode();
    root->freq = 0;
    for (int i = 0; i < n; i++)
        insert(root, arr[i]);

    // Create an array to store all prefixes
    char prefix[MAX_WORD_LEN];

    // Print all prefixes using Trie Traversal
    dfs(root, prefix, 0);
}

// Driver function.
int main()
{
    string arr[] = {"zebra", "dog", "duck", "dove"};
    int n = sizeof(arr) / sizeof(arr[0]);
    find_prefixes(arr, n);

    return 0;
}