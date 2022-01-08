#include <bits/stdc++.h>
using namespace std;
bool custom_comp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}
int activity_selection(int start[], int finish[], int n)
{
    // first to sort the jobs according to the finish time
    vector<pair<int, int>> jobs(n);
    for (int i = 0; i < n; i++)
    {
        jobs[i] = {start[i], finish[i]};
    }
    //sort the jobs according to the finishing time
    sort(jobs.begin(), jobs.end(), custom_comp);
    //we can always schedule or select the first job so initially the res=1
    int res = 1;
    //store previous selected job at previous
    auto last_selected_job = jobs[0];
    //now start from the second job
    for (int i = 1; i < n; i++)
    {
        //if the start time of the curent job is greater than the finish time of the previously selected job select it
        if (jobs[i].first > last_selected_job.second)
        {
            res++;
            //also make this last selected job
            last_selected_job = jobs[i];
        }
    }
    return res;
} //time complxity O(N*log(N)) space complexity O(N)
int main()
{
    int n;
    cin >> n;
    int *start, *finish;
    start = new int[n];
    finish = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> start[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> finish[i];
    }
    cout << activity_selection(start, finish, n) << endl;
    delete (start, finish);
    return 0;
}