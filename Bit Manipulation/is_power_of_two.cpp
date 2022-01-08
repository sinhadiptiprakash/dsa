#include <bits/stdc++.h>
using namespace std;
bool is2Power(unsigned int n)
{
    //as 0 is not a power of two we return false
    if (n == 0)
        return false;
    //if the MSB is 1 and all the other bits are 0 then we can say that n is a power of 2
    //so if we do and operation between n and n-1 we will get 0
    //so as in that case we have to return true we return not of that result
    return !(n & n - 1);
}
int main()
{
    return 0;
}