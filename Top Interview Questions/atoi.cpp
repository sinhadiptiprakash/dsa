#include <bits/stdc++.h>
using namespace std;
int myAtoi(string s)
{
    int i = 0, flag = 0;
    double c = 0;
    while (s[i] == ' ')
        i++;
    if (s[i] == '-')
    {
        flag = 1;
        i++;
    }
    else if (s[i] == '+')
        i++;
    while ((s[i] - '0') < 10 && (s[i] - '0') >= 0)
    {
        c = c * 10 + (s[i] - 48);
        if (c > INT_MAX)
            if (flag == 1)
                return INT_MIN;
            else
                return INT_MAX;
        i++;
    }
    if (flag == 1)
        c = c * -1;
    return c;
}
int main()
{
    return 0;
}