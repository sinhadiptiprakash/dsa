#include<bits/stdc++.h>
using namespace std;
#define speedio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mod=1e9+7;
void reverse_array(int a[],int n){
	int i=0,j=n-1;
	while(i<j){
		swap(a[i],a[j]);
		i++,j--;
	}
}
void print(int a[],int n){
	for(int i=0;i<n;i++)cout<<a[i]<<' ';
	cout<<endl;
}
int main(){
    speedio
	int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
	reverse_array(arr,n);
	print(arr,n);
    return 0;
}