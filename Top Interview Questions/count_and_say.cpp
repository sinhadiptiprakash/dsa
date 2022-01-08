#include <bits/stdc++.h>
using namespace std;
string count_and_say(int n)
{
    //ans till n iteration
    string ans;
    //base case
    if (n == 1)
        return "1";
    if (n == 2)
        return "11";
    ans = "11";

    for (int i = 3; i <= n; i++)
    {
        string temp = ""; //ans of next ith value i.e. 3,4,5 till n
        ans = ans + '#';  //any delim to end our ans string
        int count = 1;    //store consecutive same no
        for (int j = 1; j < ans.length(); j++)
        { //for next itearion of n, upr 2 tak ka ho cuka starting from 3
            if (ans[j] == ans[j - 1])
            { //if current equals to prev ... just inc the count
                count++;
            }
            else
            {
                //first---> add count/freq of no to ans;
                temp = temp + to_string(count);

                //sec-->add actual no to ans;
                temp = temp + ans[j - 1];

                //for next iteration of n,
                count = 1;
            }
        }
        ans = temp; //update your ans, and move for next iteration, do till n
    }
    return ans;
} //in the above code the though its time complexity is O(n) but it runs slow because of the string concat operations repeatedly
//below is the optimization over that bottleneckk
string countAndSay(int n)
{

    string ans = "1";
    for (int i = 1; i < n; i++)
    {
        vector<pair<char, int>> data;
        data.push_back(make_pair(ans[0], 1));
        for (int j = 1; j < ans.size(); j++)
        {
            if (ans[j] == ans[j - 1])
            {
                data[data.size() - 1].second += 1;
            }
            else
            {
                data.push_back(make_pair(ans[j], 1));
            }
        }
        // update ans string
        ans = "";
        for (int i = 0; i < data.size(); i++)
        {
            ans += to_string(data[i].second) + data[i].first;
        }
    }
    return ans;
}
int main()
{
    cout << countAndSay(6) << endl;
    return 0;
}