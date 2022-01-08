#include <bits/stdc++.h>
using namespace std;
//using greedy approach
/*
We can calculate the net amount of every person as-
Net amount = sum of all received money  - the sum of all sent money.
 
Find the person with the maximum and the minimum net amount, suppose ‘x’ person has maximum net amount ‘maxAmount’ 
and ‘y’ person has a minimum amount ‘minAmount’, then ‘y’ person will pay ‘minAmount’ to ‘x’ person 
after this transaction net amount of ‘x’ person is ‘maxAmount = maxAmount - abs( minAmouny ), 
and the net amount of ‘y’ person is ‘0’,

Repeat this process until all the amount will not settle or ‘0’.

Algorithm-

Create a net amount array ‘netAmount’
Fill this array, Now for every friend ‘i’
‘netAmount[i]’= sum of all received money by ‘i-th’ friend - the sum of all sent money by ‘i-th’ friend.
Create a 2-D matrix to store the ‘answer’.
Iterate a while loop until all the values of ‘netAmount’ is not ‘0’
Find the minimum and maximum of ‘netAmount’
Suppose ‘x’ index value is the max net amount and ‘y’ index is min net amount, then:
‘netAmount[x] = netAmount[x]- abs( netAmount[y] )’
Update ‘answer[y][x] = abs( netAmount[y] )
It represents that the ‘y-th’ friend will pay ‘netAmount[y]’ to ‘x-th’ friend.
Set ‘netAmount[y] = 0’.
In the end, return ‘answer’.
*/
int min_element_index(vector<int> net_amount)
{
    int min_element = INT_MAX, min_index;
    for (int i = 0; i < net_amount.size(); i++)
    {
        if (net_amount[i] < min_element)
        {
            min_index = i;
            min_element = net_amount[i];
        }
    }
    return min_index;
}
int max_element_index(vector<int> net_amount)
{
    int max_element = INT_MIN, max_index;
    for (int i = 0; i < net_amount.size(); i++)
    {
        if (net_amount[i] > max_element)
        {
            max_index = i;
            max_element = net_amount[i];
        }
    }
    return max_index;
}
vector<vector<int>> minimize_cashflow(vector<vector<int>> &transactions)
{
    int n = transactions.size();
    vector<vector<int>> minimized_transactions;
    //modify the transactions and store the the modified net_amount[i]=total recieved money-total spent money
    vector<int> net_amount(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            net_amount[i] -= transactions[i][j];
            net_amount[j] += transactions[i][j];
        }
    }
    int max_debtor = min_element_index(net_amount), max_creditor = max_element_index(net_amount);
    while (true)
    {
        if (net_amount[max_debtor] == 0 && net_amount[max_creditor] == 0)
            return minimized_transactions;
        net_amount[max_creditor] -= abs(net_amount[max_debtor]);
        //as max_debtor gives abs(net_amount[max_debtor]) to max_creditor so we have to put this transaction to answer
        minimized_transactions.push_back({max_debtor, max_creditor, abs(net_amount[max_debtor])});
        net_amount[max_debtor] = 0;
        //updating the max_debtor with next min elemnt
        max_debtor = min_element_index(net_amount);
        //updating the max_creditor with next max element
        max_creditor = max_element_index(net_amount);
    }
    return minimized_transactions;
}
int main()
{
    vector<vector<int>> transactions(3);
    transactions = {
        {0, 1000, 2000},
        {0, 0, 5000},
        {0, 0, 0},
    };
    vector<vector<int>> transactions2 = {
        {0, 2000, 4000},
        {0, 0, 3000},
        {0, 0, 0}};
    auto res = minimize_cashflow(transactions2);
    for (auto it : res)
    {
        cout << it[0] << ' ' << it[1] << ' ' << it[2] << endl;
    }
    return 0;
}