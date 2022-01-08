#include <bits/stdc++.h>
using namespace std;
int min_value(string str, int k)
{
    int l = str.length(); // find length of string

    // if K is greater than length of string
    // so reduced string will become 0
    if (k >= l)
        return 0;

    // Else find Frequency of each character and
    // store in an array
    int frequency[26] = {0};
    for (int i = 0; i < l; i++)
        frequency[str[i] - 'a']++;

    // Push each char frequency into a priority_queue
    priority_queue<int> q;
    for (int i = 0; i < 26; i++)
    {
        if (frequency[i] > 0)
            q.push(frequency[i]);
    }

    // Removal of K characters
    while (k--)
    {
        // Get top element in priority_queue,
        // remove it. Decrement by 1 and again
        // push into priority_queue
        int temp = q.top();
        q.pop();
        temp = temp - 1;
        q.push(temp);
    }

    // After removal of K characters find sum
    // of squares of string Value
    int result = 0; // Initialize result
    while (!q.empty())
    {
        int temp = q.top();
        result += temp * temp;
        q.pop();
    }

    return result;
}
int main()
{
    string s;
    int k;
    cin >> s >> k;
    cout << min_value(s, k) << endl;
    return 0;
}