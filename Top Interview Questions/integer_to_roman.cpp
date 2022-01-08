#include <bits/stdc++.h>
using namespace std;
string intToRoman(int number)
{
    int num[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    string s[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int i = 12;
    string ans = "";
    while (number > 0)
    {
        int div = number / num[i];
        number = number % num[i];
        while (div--)
        {
            ans += s[i];
        }
        i--;
    }
    return ans;
}
int main()
{
    return 0;
}