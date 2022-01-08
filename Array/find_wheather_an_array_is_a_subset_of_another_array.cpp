#include<bits/stdc++.h>
using namespace std;
bool is_array_subset_of_another_array(int a1[],int a2[],int n,int m){
    //for storing the occurences/frequencies of elements of a1
    unordered_set<int> set;
    //storing the frequencies of a1
    for(int i=0;i<n;i++){
        set.emplace(a1[i]);
    }
    //now traversing the a2, if all the elements of a2 are present in set i.e. in a1
    //we can say that a2 is a subset of a1
    for(int i=0;i<m;i++){
        if(set.find(a2[i])==set.end())
            return false;
    }
    return true;
}//time complexity is O(N) space complexity is O(N)
int main(){
    int a1[] = {10, 5, 2, 23, 19};
    int a2[] = {19, 5, 2};
    int n=sizeof(a1)/sizeof(int);
    int m=sizeof(a2)/sizeof(int);
    cout<<is_array_subset_of_another_array(a1,a2,n,m)<<endl;
    return 0;
}