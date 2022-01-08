#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define speedio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mod=1e9+7;
// here we can also use the same two strategies as in the sorting 0 1 2
void move_negatives_to_left(int a[],int n){
    int low=0;
    for(int i=0;i<n;i++){
        if(a[i]<0){
            swap(a[i],a[low++]);
        }
    }
}
void print(int a[],int n){
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;
}
int main(){
    int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    move_negatives_to_left(arr,n);
    print(arr,n);
    return 0;
}