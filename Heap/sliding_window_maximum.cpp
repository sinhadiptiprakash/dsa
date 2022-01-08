#include <bits/stdc++.h>
using namespace std;
//using multiset as heap
vector<int> slidingWindowMax(int a[], int n, int k)
{
    vector<int> maximums;
    multiset<int, greater<int>> maxHeap;
    for (int i = 0; i < k - 1; i++)
        maxHeap.insert(a[i]);
    for (int i = k - 1; i < n; i++)
    {
        maxHeap.insert(a[i]);
        maximums.push_back(*maxHeap.begin());
        if (i - k + 1 >= 0)
            maxHeap.erase(a[i - k + 1]);
    }
    return maximums;
}
//the problem can be efficiently solved using Dequeue
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    auto maximums = slidingWindowMax(a, n, 4);
    for (auto i : maximums)
        cout << i << ' ';
    cout << endl;
    return 0;
}