#include<bits/stdc++.h>
using namespace std;
void cyclically_rotate_array_by_one(int a[],int n){
    //store the last element in a temp variable
    int temp=a[n-1];
    for(int i=n-1;i>=1;i--){
        a[i]=a[i-1];
    }
    a[0]=temp;
}
int main(){
    int a[]={2,3,4,5,6,1,2};
    int n=sizeof(a)/sizeof(int);
    cyclically_rotate_array_by_one(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;
    return 0;
}