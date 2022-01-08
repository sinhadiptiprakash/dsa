#include <bits/stdc++.h>
using namespace std;
int countPrimes(int n)
{
    if (n == 0)
        return 0;
    vector<bool> primes(n, true);
    primes[0] = primes[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (primes[i])
        {
            for (int j = i * i; j < n; j += i)
            {
                primes[j] = false;
            }
        }
    }
    int count = 0;
    for (int i = 2; i < n; i++)
        if (primes[i])
            count++;
    return count;
}
int main()
{
    return 0;
}