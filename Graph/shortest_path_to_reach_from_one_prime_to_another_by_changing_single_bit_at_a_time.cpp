#include <bits/stdc++.h>
using namespace std;
vector<bool> primes;
vector<int> graph[10000];
void sieveOfEratosthenes()
{
    vector<bool> sieves(9999, 1);
    sieves[0] = sieves[1] = 0;
    for (int p = 2; p <= 100; p++)
    {
        if (sieves[p])
        {
            for (int j = p * p; j <= 10000; j += p)
                sieves[j] = 0;
        }
    }
    for (int i = 1000; i <= 9000; i++)
    {
        if (sieves[i])
            primes.push_back(i);
    }
}
bool compare(string s1, string s2)
{
    // To compare the digits represented by strings
    int c = 0;
    if (s1[0] != s2[0])
        if (s1[1] != s2[1])
            c++;
    if (s1[2] != s2[2])
        c++;
    if (s1[3] != s2[3])
        c++;
    // If the numbers differ only by a single digit return true else false
    return (c == 1);
}
void *buildGraph()
{
    int sz = primes.size();
    for (int i = 0; i < sz; i++)
    {
    }
}
int main()
{
    return 0;
}