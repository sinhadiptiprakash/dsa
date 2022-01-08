#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a = {7,4,1,9,3,1,7,6,0};
    next_permutation(a.begin(), a.end());
    for (int i:a)
        cout << i;
    cout << endl;
    return 0;
}