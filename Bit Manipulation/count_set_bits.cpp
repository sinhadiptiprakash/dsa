#include <bits/stdc++.h>
using namespace std;
int countSetBits(int n)
{
    int cnt = 0;
    while (n)
    {
        if (n & 1)
            cnt++;
        n >>= 1;
    }
    return cnt;
}
//time complexity O(log(n))
int countSetBitsByNibbles(int n)
{
    int nibbles[] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
    int cnt = 0;
    while (n)
    {
        cnt += nibbles[n & 0xF]; // n& 0xF means we are doing and operation between the last 4 digits and 15
        n >>= 4;
    }
    return cnt;
}
int main()
{
    int n;
    cin >> n;
    cout << countSetBitsByNibbles(n) << endl;
    return 0;
}