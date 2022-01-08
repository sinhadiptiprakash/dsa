#include<bits/stdc++.h>
using namespace std;
//this function handles special cases such as all numbers are negative
int kadane_algorithm(int a[],int n){
    int max_so_far,max_ending_here;
    //initializing both of this to first element of the array
    max_so_far=max_ending_here=a[0];
    for(int i=1;i<n;i++){
        //first we add curent element with max_endin_here
        max_ending_here+=a[i];
        //if max_ending_here is less than curent element we start max_ending_here with only curent element
        if(max_ending_here<a[i]){
            max_ending_here=a[i];
        }
        //if max_ending_here is greater than the max_so_far then we update the max_sofar
        if(max_ending_here>max_so_far){
            max_so_far=max_ending_here;
        }
    }
    return max_so_far;
}
int main(){
    int a[]={-2,-3,4,-1,-2,1,5,-3};
    int b[]={-2,-3,1,-4,-6};
    int c[]={-3,-2,-1,-4};
    int n=sizeof(c)/sizeof(int);
    cout<<kadane_algorithm(c,n)<<endl;
    return 0;
}