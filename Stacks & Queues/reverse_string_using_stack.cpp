#include <bits/stdc++.h>
using namespace std;
string reverse_string(string s)
{
    stack<char> st;
    for (char c : s)
    {
        st.push(c);
    }
    string res = "";
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    return res;
}
int main()
{
    string s;
    cin >> s;
    cout << reverse_string(s) << endl;
    return 0;
}