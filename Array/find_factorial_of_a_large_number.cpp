#include <bits/stdc++.h>
using namespace std;

vector<int> factorial(int n)
{
    vector<int> ans;
    ans.push_back(1);
    int carry = 0;

    for (int i = 2; i <= n; i++)
    {

        for (int j = ans.size() - 1; j >= 0; j--)
        {
            int product = ((ans[j] * i) + carry);
            carry = product / 10;
            ans[j] = product % 10;
        }

        if (carry == 0)
            continue;

        while (carry != 0)
        {
            ans.insert(ans.begin(), carry % 10);
            carry /= 10;
        }

        carry = 0;
    }
    return ans;
}
// Driver program
int main()
{
    auto res = factorial(8);
    for (int i = 0; i < res.size(); i++)
        cout << res[i];
    cout << endl;
    return 0;
}