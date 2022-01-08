#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define speedio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mod=1e9+7;
//returns pair of min and max element in an array
pair<int,int> min_max(int a[],int n){
    pair<int,int> result;
    result.first=INT_MAX,result.second=INT_MIN;
    for(int i=0;i<n;i++){
        if(a[i]>result.second)result.second=a[i];
        if(a[i]<result.first)result.first=a[i];
    }
    return result;
}
int main(){
    speedio
	int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
	pair<int,int> result=min_max(arr,n);
    cout<<result.first<<' '<<result.second<<endl;
    return 0;
}