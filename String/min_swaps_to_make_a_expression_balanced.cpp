#include <bits/stdc++.h>
using namespace std;

int minSwaps(string s)
{
    int ans = 0;
    int depth = 0;
    for (char x : s)
    {
        if (x == '[')
            depth++;
        else
            depth--;

        if (depth < 0)
        {
            ans++;
            depth = 0;
        }
    }
    if (ans & 1)
        ans = ans / 2 + 1;
    else
        ans /= 2;

    return ans;
}
int main()
{
    string s = "[]][][";
    cout << minSwaps(s) << "\n";

    s = "[[][]]";
    cout << minSwaps(s) << "\n";

    s = "[]]]][][][";
    cout << minSwaps(s) << "\n";
    return 0;
}