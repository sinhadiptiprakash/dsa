#include <bits/stdc++.h>
using namespace std;
string first_non_repeating(string A)
{
    int arr[26] = {0};
    queue<char> q;
    string res = "";
    for (int i = 0; i < A.length(); i++)
    {
        arr[A[i] - 'a']++;
        q.push(A[i]);
        while (!q.empty() && arr[q.front() - 'a'] > 1)
        {
            q.pop();
        }
        if (q.empty())
            res.push_back('#');
        else
            res.push_back(q.front());
    }
    return res;
}
int main()
{
    string A;
    cin >> A;
    cout << first_non_repeating(A) << endl;
    return 0;
}