#include <bits/stdc++.h>
using namespace std;
int maxDif(string &str)
{
    int n = str.length();
    int sum = 0;
    int max_sum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int x = (str[i] == '0') ? 1 : -1;
        sum += x;
        max_sum = max(max_sum, sum);
        if (sum < 0)
            sum = 0;
    }
    return max_sum;
}
int main()
{
    string s;
    cin >> s;
    cout << maxDif(s) << endl;
    return 0;
}