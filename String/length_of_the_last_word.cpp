#include <bits/stdc++.h>
using namespace std;
int findLength(string s)
{
    int n = s.length();
    int cnt = 0;
    bool flag = false;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == ' ')
        {
            if (flag)
            {
                return cnt;
            }
        }
        else
        {
            cnt += 1;
            flag = true;
        }
    }
    if (flag)
        return cnt;
}
int main()
{
    return 0;
}