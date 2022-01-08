#include <bits/stdc++.h>
using namespace std;
//using binary search to get int part of the square root
int sqruare_rt(int x)
{
    int low = 1, high = x - 1, mid, check;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        check = mid * mid;
        if (check == x)
            return mid;
        else if (check < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high;
}
// to get real square root in double
double square_root(int n)
{
    double lo = 1, hi = n, mid, val;
    while (lo < hi)
    {
        mid = lo + (hi - lo) / 2;
        val = mid * mid;
        if (val == n)
            return mid;
        else if (val > n)
            hi = mid - 0.000001;
        else
            lo = mid + 0.000001;
    }
    return hi;
}
int main()
{
    cout << square_root(60) << endl;
    cout << sqrt(60) << endl;
    return 0;
}