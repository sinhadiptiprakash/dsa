#include <bits/stdc++.h>
using namespace std;
struct Node
{
    char ch;
    Node *prev, *next;
    Node(char ch)
    {
        this->ch = ch;
        prev = NULL;
        next = NULL;
    }
};
Node *head, *tail;
void addNode(Node *node)
{
    node->next = tail;
    node->prev = tail->prev;
    tail->prev = node;
    node->prev->next = node;
}
void deleteNode(Node *node)
{
    node->prev->next = node->next;
    node->next->prev = node->prev;
    node->next = NULL;
    node->prev = NULL;
}
string firstNonRepeating(string s)
{
    int n = s.size();
    string res = "";
    head = new Node('#');
    tail = new Node('#');
    head->next = tail;
    tail->prev = head;
    unordered_map<char, Node *> mp;
    vector<bool> repeated(256, 0);
    for (int i = 0; i < n; i++)
    {
        if (!repeated[s[i]] && !mp[s[i]])
        {
            Node *lastNonRepeating = new Node(s[i]);
            addNode(lastNonRepeating);
            mp[s[i]] = tail->prev;
        }
        else if (mp[s[i]] && !repeated[s[i]])
        {
            repeated[s[i]] = true;
            deleteNode(mp[s[i]]);
            mp.erase(s[i]);
        }
        res.push_back(head->next->ch);
    }
    return res;
}
int main()
{
    string s;
    cin >> s;
    cout << firstNonRepeating(s) << endl;
    return 0;
}