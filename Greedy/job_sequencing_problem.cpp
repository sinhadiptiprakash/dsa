#include <bits/stdc++.h>
using namespace std;
/*
Algorithm:
1) Sort all jobs in decreasing order of profit. 
2) Iterate on jobs in decreasing order of profit.For each job , do the following :
    For each job find an empty time slot from deadline to 0. If found empty slot put the job in the slot 
    and mark this slot filled.
*/
struct Job
{
    int id;
    int dead;
    int profit;
};
class Solution
{
public:
    static bool custom_comp(const Job &a, const Job &b)
    {
        return a.profit > b.profit;
    }
    vector<int> job_sequencing_problem(Job arr[], int n)
    {
        sort(arr, arr + n, custom_comp);
        //to keep track of the free time slot, initially all slots are free
        //when a slot is get allocated we assign it with the index of that job because one slot is allocated at once
        vector<bool> slot(n, 0);
        //for counting the no. of selected jobs
        int count = 0;
        //max_profit by completing the jobs within their deadline
        int max_profit = 0;
        //now for each job we will try to give it the maximum possible free slot to maximize the no. of jobs selected
        for (int i = 0; i < n; i++)
        {
            // Find a free slot for this job (Note that we start from the last possible slot)
            for (int j = min(n, arr[i].dead) - 1; j >= 0; j--)
            {
                if (!slot[j])
                {
                    slot[j] = i; //make this slot booked
                    max_profit += arr[i].profit;
                    count++;
                    break;
                }
            }
        }
        // Print the result
        // for (int i = 0; i < n; i++)
        //     if (slot[i] != 1)
        //         cout << arr[slot[i]].id << " ";
        return {count, max_profit};
    }
};
int main()
{
    Solution s;
    Job arr[] = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    int n = sizeof(arr) / sizeof(Job);
    auto res = s.job_sequencing_problem(arr, n);
    cout << res[0] << ' ' << res[1] << endl;
    return 0;
}