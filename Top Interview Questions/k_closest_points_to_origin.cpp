#include <bits/stdc++.h>
using namespace std;
struct comp
{
public:
    bool operator()(const pair<int, vector<int>> a, const pair<int, vector<int>> b)
    {
        return a.first > b.first;
    }
};
vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, comp> pq;
    for (int i = 0; i < points.size(); i++)
    {
        pq.push({pow(abs(points[i][0]), 2) + pow(abs(points[i][1]), 2), points[i]});
    }
    vector<vector<int>> res;
    int i = 0;
    while (!pq.empty() && i < k)
    {
        auto it = pq.top();
        pq.pop();
        res.push_back(it.second);
        i++;
    }
    return res;
}
int main()
{
    return 0;
}