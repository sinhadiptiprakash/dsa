// Maximum Average Pass Ratio
// also known as five start seller
#include <bits/stdc++.h>
using namespace std;
// Because each class's pass ratio is weighted equally, it's always optimal to put the student in the class
// that makes the biggest change among all the other classes.
typedef pair<double, pair<int, int>> ii;

inline double getRatio(int x, int y)
{
    return (double)x / y;
}
double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
{
    double ans = 0;
    int k = extraStudents;
    priority_queue<ii> pq;
    // we are pushing the pairs by just changing the no. of passed and total students by 1
    for (auto c : classes)
        pq.push({getRatio(c[0] + 1, c[1] + 1) - getRatio(c[0], c[1]), {c[0], c[1]}});
    while (!pq.empty() && k)
    {
        auto curr = pq.top();
        int x = curr.second.first;
        int y = curr.second.second;
        pq.pop();
        pq.push({getRatio(x + 2, y + 2) - getRatio(x + 1, y + 1), {x + 1, y + 1}});
        k--;
    }
    while (!pq.empty())
    {
        ans += getRatio(pq.top().second.first, pq.top().second.second);
        pq.pop();
    }
    return ans / classes.size();
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> classes(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> classes[i][0] >> classes[i][1];
    }
    int extraStudents;
    cin >> extraStudents;
    cout << maxAverageRatio(classes, extraStudents) << endl;
    return 0;
}