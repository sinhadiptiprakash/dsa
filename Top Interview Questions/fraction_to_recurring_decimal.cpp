#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string fractionToDecimal(long long num, long long den)
    {
        if (num == 0) //numerator ==0
            return "0";
        int res = 1; //storing sign
        if (num < 0)
            res = res * (-1), num = num * (-1);
        if (den < 0)
            res = res * (-1), den = den * (-1);
        string ans = "";  //storing ans
        long long rem, q; //remainder, quotient
        rem = num % den;
        q = num / den;
        if (rem == 0) //divisible
        {
            ans += to_string(q);
        }
        else
        {
            ans += to_string(q) + '.';
            unordered_map<long long, int> m; //to store rem and length of string at which
                //this rem occured to add brackets if needed
            while (rem != 0)
            {
                if (m.find(rem) != m.end()) //remainder already occured
                {
                    ans.insert(ans.begin() + m[rem], '('); //adding ( at the point where rem occured
                    ans += ')';
                    break;
                }
                m[rem] = ans.size();
                num = rem * 10;
                q = num / den;
                rem = num % den;
                ans += to_string(q);
            }
        }
        if (res == -1)
            ans.insert(ans.begin(), '-');
        return ans;
    }
};
int main()
{
    return 0;
}