#include <bits/stdc++.h>
using namespace std;
class compare
{
public:
    bool operator()(string s1, string s2)
    {                   // Modifeid lexicographical sort(dictionary order sort)
        string v1 = s1; // suppose s1="3"
        string v2 = s2; // suppose s2="30" , general lexico sort will say s2>s1 but it will fail our result if we try to combine in this order
        v1 += s2;       // now v1="330"
        v2 += s1;       // now v2="303"
        return v1 > v2; // modified lexico sort checks which combination gives larger result and reutrns corresponding order
                        // btw here s1(3)>s2(30)  as it gives greater result
    }
};

string largestNumber(vector<int> &nums)
{
    vector<string> tokens;

    for (auto e : nums) // converting nums element (int) int0 tokens elements (string)
    {
        string s = to_string(e);
        tokens.push_back(s);
    }

    sort(tokens.begin(), tokens.end(), compare()); // calling modified lexicograhical sort

    string str = "";
    for (auto e : tokens) // generating our output string
        str += e;

    while (str[0] == '0' and str[1] == '0') // to avoid duplicates zeroes at the begining
        str = str.substr(1);

    return str;
}

int main()
{
    return 0;
}