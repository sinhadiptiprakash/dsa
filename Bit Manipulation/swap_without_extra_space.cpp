#include <bits/stdc++.h>
using namespace std;
void swapWithoutExtra(int &x, int &y)
{
    if (x != y)
    {
        x = x ^ y;
        y = x ^ y;
        x = x ^ y;
    }
}
int main()
{
    return 0;
}