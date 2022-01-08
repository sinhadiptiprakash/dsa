#include <bits/stdc++.h>
using namespace std;
vector<bool> sieve(int n)
{
    vector<bool> primes(n + 1, 1);
    primes[0] = primes[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (primes[i])
        {
            for (int j = i * i; j <= n; j += i)
                primes[j] = 0;
        }
    }
    return primes;
}
int splitStringIntoPrimes(string str)
{
    auto primes = sieve(1000);
    int n = str.length();
    int dp[n + 1] = {0};
    dp[0] = 1;
    const int mod = 1e9 + 7;
    for (int i = 1; i <= n; i++)
    {
        if (str[i - 1] != '0' && primes[stoi(str.substr(i - 1, 1))])
            dp[i] = dp[i - 1];

        if (i - 2 >= 0 && str[i - 2] != '0' && primes[stoi(str.substr(i - 2, 2))])
            dp[i] = (dp[i] + dp[i - 2]) % mod;

        if (i - 3 >= 0 && str[i - 3] != '0' && primes[stoi(str.substr(i - 3, 3))])
            dp[i] = (dp[i] + dp[i - 3]) % mod;
    }
    return dp[n];
}
int main()
{
    string str;
    cin >> str;
    cout << splitStringIntoPrimes(str) << endl;
    return 0;
}