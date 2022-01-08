#include <bits/stdc++.h>
using namespace std;
struct comp
{
    bool operator()(const pair<int, string> &a, const pair<int, string> &b)
    {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    }
};
vector<string> topKFrequent(vector<string> &words, int k)
{
    unordered_map<string, int> mp;
    for (string w : words)
        mp[w]++;
    priority_queue<pair<int, string>, vector<pair<int, string>>, comp> pq;
    for (auto it : mp)
    {
        pq.push({it.second, it.first});
    }
    vector<string> res;
    while (!pq.empty() && k--)
    {
        res.push_back(pq.top().second);
        pq.pop();
    }
    return res;
}
int main()
{

    return 0;
}