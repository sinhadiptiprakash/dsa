#include <bits/stdc++.h>
using namespace std;
//below is the recursive approach
/*
1) First sort jobs according to finish time.
2) Now apply following recursive process. 
   // Here arr[] is array of n jobs
   findMaximumProfit(arr[], n)
   {
     a) if (n == 1) return arr[0];
     b) Return the maximum of following two profits.
         (i) Maximum profit by excluding current job, i.e., 
             findMaximumProfit(arr, n-1)
         (ii) Maximum profit by including the current job            
   }
*/
class Job
{
public:
    int start, finish, profit;
};
//below is the custom comparator for sorting
bool comp(const Job &a, const Job &b)
{
    return (a.finish < b.finish);
}
// Find the latest job (in sorted array) that doesn't
// conflict with the job[i]. If there is no compatible job,
// then it returns -1.
int latest_non_conflict(Job arr[], int i)
{
    for (int j = i - 1; j >= 0; j--)
    {
        if (arr[j].finish <= arr[i - 1].start)
            return j;
    }
    return -1;
}
//we pass the sorted jobs array to the below function
int job_scheduling(Job jobs[], int n)
{
    //if there is only one job to schedule return the profit of that only
    if (n == 1)
        return jobs[n - 1].profit;
    // Find profit when current job is included
    int inclProf = jobs[n - 1].profit;
    int i = latest_non_conflict(jobs, n);
    if (i != -1)
        inclProf += job_scheduling(jobs, i + 1);

    // Find profit when current job is excluded
    int exclProf = job_scheduling(jobs, n - 1);

    return max(inclProf, exclProf);
}
int findMaxProfit(Job jobs[], int n)
{
    // Sort jobs according to finish time
    sort(jobs, jobs + n, comp);

    return job_scheduling(jobs, n);
} //time complexity O(n*2^n)

//below is the dynamic programming solution
// The main function that returns the maximum possible
// profit from given array of jobs
int findMaxProfit(Job arr[], int n)
{
    // Sort jobs according to finish time
    sort(arr, arr + n, comp);

    // Create an array to store solutions of subproblems.  table[i]
    // stores the profit for jobs till arr[i] (including arr[i])
    int *table = new int[n];
    table[0] = arr[0].profit;

    // Fill entries in M[] using recursive property
    for (int i = 1; i < n; i++)
    {
        // Find profit including the current job
        int inclProf = arr[i].profit;
        int l = latest_non_conflict(arr, i);
        if (l != -1)
            inclProf += table[l];

        // Store maximum of including and excluding
        table[i] = max(inclProf, table[i - 1]);
    }

    // Store result and free dynamic memory allocated for table[]
    int result = table[n - 1];
    delete[] table;

    return result;
} //time complexity O(N^2) space complexity O(N)

//below is the dynamic + binary search approach
// in this approach the the latest_non_conflict is optimized by binary search
// A Binary Search based function to find the latest job
// (before current job) that doesn't conflict with current
// job.  "index" is index of the current job.  This function
// returns -1 if all jobs before index conflict with it.
// The array jobs[] is sorted in increasing order of finish
// time.
int binarySearch(Job jobs[], int index)
{
    // Initialize 'lo' and 'hi' for Binary Search
    int lo = 0, hi = index - 1;

    // Perform binary Search iteratively
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (jobs[mid].finish <= jobs[index].start)
        {
            if (jobs[mid + 1].finish <= jobs[index].start)
                lo = mid + 1;
            else
                return mid;
        }
        else
            hi = mid - 1;
    }

    return -1;
}
int findMaxProfitEfficient(Job arr[], int n)
{
    // Sort jobs according to finish time
    sort(arr, arr + n, comp);

    // Create an array to store solutions of subproblems.  table[i]
    // stores the profit for jobs till arr[i] (including arr[i])
    int *table = new int[n];
    table[0] = arr[0].profit;

    // Fill entries in table[] using recursive property
    for (int i = 1; i < n; i++)
    {
        // Find profit including the current job
        int inclProf = arr[i].profit;
        int l = binarySearch(arr, i);
        if (l != -1)
            inclProf += table[l];

        // Store maximum of including and excluding
        table[i] = max(inclProf, table[i - 1]);
    }

    // Store result and free dynamic memory allocated for table[]
    int result = table[n - 1];
    delete[] table;

    return result;
}
int main()
{
    Job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The optimal profit is " << findMaxProfitEfficient(arr, n) << endl;
    return 0;
}