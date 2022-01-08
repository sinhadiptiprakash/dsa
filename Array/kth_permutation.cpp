#include <bits/stdc++.h>
using namespace std;
string getPermutation(int n, int k)
{
    vector<int> num;
    int fact = 1;
    for (int i = 1; i < n; i++)
    {
        fact *= i;
        num.push_back(i);
    }
    num.push_back(n);
    string s = "";
    k--;
    while (true)
    {
        int p = k / fact;
        s += to_string(num[p]);
        num.erase(num.begin() + p);
        if (num.empty())
            break;
        k = k % fact;
        fact /= num.size();
    }
    return s;
}
int main()
{
    int n, k;
    cin >> n >> k;
    cout << getPermutation(n, k) << endl;
    return 0;
}