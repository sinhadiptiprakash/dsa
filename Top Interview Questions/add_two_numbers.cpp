#include <bits/stdc++.h>
using namespace std;
int getSum(int x, int y)
{
    while (y)
    {
        // following is the carry, unsigned here to handle the negative integer case
        unsigned carry = x & y;
        // the sum without carry is x^y which will be stored in x
        x = x ^ y;
        // Carry is shifted by one so that adding it to x gives the required sum
        y = carry << 1;
    }
    return x;
}
int main()
{
    int x, y;
    cin >> x >> y;
    cout << getSum(x, y) << endl;
    return 0;
}