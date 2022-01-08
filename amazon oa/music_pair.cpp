// Pairs of Songs With Total Durations Divisible by 60
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    inline int count(int n)
    {
        return n * (n - 1) / 2;
    }

    int numPairsDivisibleBy60(vector<int> &time)
    {
        vector<int> mod(60, 0);
        for (auto v : time)
        {
            mod[v % 60]++;
        }
        int ans = count(mod[0]);
        ans += count(mod[30]);

        for (int i = 1; i <= 29; i++)
        {
            ans += mod[i] * mod[60 - i];
        }

        return ans;
    }
};

int main()
{
    return 0;
}