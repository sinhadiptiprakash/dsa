#include <bits/stdc++.h>
using namespace std;
//below function return the first element from the right in vector that is less than or equals to target
int binary_search(vector<int> a, int n, int target)
{
    int low = 0, high = n - 1, mid, res;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (a[mid] > target)
            high--;
        else
        {
            res = mid;
            low++;
        }
    }
    return res;
}
int main()
{
    int n, q, m, d;
    cin >> n;
    //vector power stores powers of all n soldiers
    vector<int> power(n), prefix_sum(n);
    //taking input for power array
    for (int i = 0; i < n; i++)
    {
        cin >> d;
        power[i] = d;
    }
    //sort the power array to make it eligible for binary search
    sort(power.begin(), power.end());
    //below loop computes the prefix sum of the sorted array to get the sum upto i th index in constant time
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            prefix_sum[i] = power[i];
        else
            prefix_sum[i] = prefix_sum[i - 1] + power[i];
    }
    //taking the input of q
    cin >> q;
    while (q--)
    {
        //taking input of m which is the power of bishu
        cin >> m;
        // searching index of first element which is less than or equals to target from right
        int index = binary_search(power, n, m);
        //we get the sum of the powers of the soldiers which are beaten by bishu with his power m
        int res = prefix_sum[index];
        //as the no. of beaten soldiers is index+1
        cout << index + 1 << ' ' << res << endl;
    }
    return 0;
}