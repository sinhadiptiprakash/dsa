#include<bits/stdc++.h>
using namespace std;
int kadandeAlgorithm(int a[],int n){
    int maxSoFar = a[0];
    int curMax = a[0];

    for (int i = 1; i < n; i++)
    {
        curMax = max(a[i], curMax + a[i]);
        maxSoFar = max(maxSoFar, curMax);
    }
    return maxSoFar;
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n;i++)
        cin >> a[i];
    cout << kadandeAlgorithm(a, n) << endl;
    return 0;
}