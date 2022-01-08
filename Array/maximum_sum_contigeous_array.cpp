#include<bits/stdc++.h>
using namespace std;
//here we have used the same concept as kadane's algorithm 
//below function can also handle the case when all the array elements are negative 
//if so then return the max element of the array
int maximum_sum_contigeous_array(int a[],int n){
    int max_so_far = a[0];
    int curr_max = a[0];
 
   for(int i = 1; i < n; i++){
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
   }
   return max_so_far;
}
int main(){
    int a[] = {-3,-2,-9,-4,-2,-3,-15};
    int n=sizeof(a)/sizeof(int);
    cout<<maximum_sum_contigeous_array(a,n)<<endl;
    return 0;
}