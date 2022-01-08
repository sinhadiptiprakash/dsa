#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[]={19,4,5,6,8,1,29,0};
    int n=sizeof(a)/sizeof(int);
    sort(a,a+n,greater<int>());
    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;
    vector<int> arr={3,4,5,1,9,0,1,2,9};
    sort(arr.begin(),arr.end(),greater<int>());
    for(auto i:arr)cout<<i<<' ';
    cout<<endl;
    return 0;
}