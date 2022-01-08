#include<bits/stdc++.h>
using namespace std;
//recursive
double myPow(double x, int n1)
{
    long n = n1;
    if (n < 0)
    {
        n = -n;
        x = 1 / x;
    }
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    if (n % 2 == 0)
        return myPow(x * x, n / 2);
    else
        return x * myPow(x * x, (n - 1) / 2);
}
//iterative approach
double myPow(double x, int n)
{
    double ans = 1;
    bool neg = 0;
    if (n < 0)
        neg = 1;
    n = abs(n);
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            ans *= x;
        }
        x = x * x;
        n /= 2;
    }
    if (!neg)
        return ans;
    return 1.0 / ans;
}
int main(){
    return 0;
}