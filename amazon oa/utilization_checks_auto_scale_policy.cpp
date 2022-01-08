#include <bits/stdc++.h>
using namespace std;
bool compare(const vector<int> &a, const vector<int> &b)
{
    return a[1] < b[1];
}
vector<vector<int>> getPairs(vector<vector<int>> &a, vector<vector<int>> &b, int target)
{
    vector<vector<int>> res;
    sort(a.begin(), a.end(), compare); //O(nlogn)
    sort(b.begin(), b.end(), compare);
    int left = 0, right = b.size() - 1;
    int previousMaxSum = INT_MIN;
    while (left < a.size() && right >= 0)
    { // O(m+n)
        int curentSum = a[left][1] + b[right][1];
        if (curentSum > target)
        {
            right--;
        }
        else
        {
            if (previousMaxSum <= curentSum)
            {
                if (previousMaxSum < curentSum)
                { // move as close as possible to target
                    previousMaxSum = curentSum;
                    res.clear(); // rest res since find new closer pair
                }
                // push current closer pair to result
                res.push_back({a[left][0], b[right][0]});
                // check duplicate of vector b
                int index = right - 1;
                while (index >= 0 && b[index][1] == b[right][1])
                {
                    res.push_back({a[left][0], b[index--][0]});
                }
            }
            left++;
        }
    }
    return res;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(2)), b(m, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i][0] >> b[i][1];
    }
    int target;
    cin >> target;
    auto res = getPairs(a, b, target);
    for (auto v : res)
    {
        for (int i : v)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}