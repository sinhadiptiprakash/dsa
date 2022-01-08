#include <bits/stdc++.h>
using namespace std;
long long minCost(long long arr[], long long n)
{
    priority_queue<long long, vector<long long>, greater<long long>> pq(arr, arr + n);
    long long cost = 0;
    long long sum = 0;
    while (pq.size() > 1)
    {
        sum = pq.top();
        pq.pop();
        sum += pq.top();
        pq.pop();
        cost += sum;
        pq.push(sum);
    }
    return cost;
}
int main()
{
    long long n = 4;
    long long arr[] = {4, 3, 2, 6};
    cout << minCost(arr, n) << endl;
    return 0;
}