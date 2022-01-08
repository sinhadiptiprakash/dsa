#include <bits/stdc++.h>
using namespace std;
//recursive
int recursive(int n, vector<int> &configurations)
{

    if (configurations[n] != -1)
        return configurations[n];

    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += recursive(i - 1, configurations) * recursive(n - i, configurations);

    return configurations[n] = sum;
}
int numOfUniqueBST(int n)
{
    vector<int> configuration(n + 1, -1);
    configuration[0] = configuration[1] = 1;
    return recursive(n, configuration);
}
int main()
{
    int n;
    cin >> n;
    cout << numOfUniqueBST(n) << endl;
    return 0;
}