#include <bits/stdc++.h>
using namespace std;
struct meeting
{
    int start;
    int finish;
    int pos;
};
bool comp(const meeting &a, const meeting &b)
{
    return a.finish < b.finish;
}
vector<int> maximum_meetings(int start[], int finish[], int n)
{
    vector<int> result;
    vector<meeting> meetings(n);
    for (int i = 0; i < n; i++)
    {
        meetings[i].start = start[i];
        meetings[i].finish = finish[i];
        meetings[i].pos = i;
    }
    sort(meetings.begin(), meetings.end(), comp);
    result.push_back(meetings[0].pos);
    int last_meeting_finish_time = meetings[0].finish;
    for (int i = 1; i < n; i++)
    {
        if (meetings[i].start >= last_meeting_finish_time)
        {
            last_meeting_finish_time = meetings[i].finish;
            result.push_back(meetings[i].pos);
        }
    }
    return result;
}
int main()
{
    // Starting time
    int s[] = {1, 3, 0, 5, 8, 5};

    // Finish time
    int f[] = {2, 4, 6, 7, 9, 9};

    // Number of meetings.
    int n = sizeof(s) / sizeof(s[0]);
    auto res = maximum_meetings(s, f, n);
    for (auto pos : res)
        cout << pos + 1 << ' ';
    cout << endl;
    return 0;
}