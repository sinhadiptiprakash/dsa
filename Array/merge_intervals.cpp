// problem link https://leetcode.com/problems/merge-intervals/
#include <bits/stdc++.h>
using namespace std;
//if the intervals are represented as a vector of pair<start,finish>
vector<pair<int, int>> merge_intervals(vector<pair<int, int>> intervals)
{
    vector<pair<int, int>> result;
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    result.push_back(intervals[0]);
    for (int i = 1; i < n; i++)
    {
        if (intervals[i].first <= result.back().second)
        {
            result.back().second = max(result.back().second, intervals[i].second);
        }
        else
        {
            result.push_back(intervals[i]);
        }
    }
    return result;
}
//if the intervals are represented as vector of vector like in the original leetcode problem
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end());
    res.push_back(intervals[0]);
    for (int i = 1; i < n; i++)
    {
        if (intervals[i][0] <= res.back()[1])
        {
            res.back()[1] = max(res.back()[1], intervals[i][1]);
        }
        else
        {
            res.push_back(intervals[i]);
        }
    }
    return res;
}
int main()
{
    vector<pair<int, int>> result, intervals, intervals2;
    intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    intervals2 = {{1, 4}, {4, 5}};
    result = merge_intervals(intervals);
    for (auto it : result)
    {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}