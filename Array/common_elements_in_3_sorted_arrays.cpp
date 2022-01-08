#include<bits/stdc++.h>
using namespace std;
//using 3 pointer approach
vector<int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3){
            // initializaion of 3 pointers from left of all the sorted arrays
            int index1=0,index2=0,index3=0;
            vector<int> result;
            // the loop runs until one of the pointer reaches the end of its corresponding array
            while(index1<n1 && index2<n2 && index3<n3){
                // if 3 elements of the 3 array pointed by the 3 pointers curently is equal 
                if(A[index1]==B[index2] && B[index2]==C[index3]){
                    // if the last added element is not the curent common element or the result is empty we add the curent common element
                    if(result.empty() || A[index1]!=result.back()){
                        result.push_back(A[index1]);
                    }
                    //we increment all the 3 pointers
                    index1++,index2++,index3++;
                }
                //else we only increment the pointer pointing the lowest element among three pointers
                else{
                    int min_element=min(A[index1],min(B[index2],C[index3]));
                    if(A[index1]==min_element)index1++;
                    else if(B[index2]==min_element)index2++;
                    else if(C[index3]==min_element)index3++;
                }
            }
            return result;
}
int main(){
    int a[]={1, 5, 10, 20, 40, 80},b[]={6, 7, 20, 80, 100},c[]={3, 4, 15, 20, 30, 70, 80, 120};
    int n1=sizeof(a)/sizeof(int);
    int n2=sizeof(b)/sizeof(int);
    int n3=sizeof(c)/sizeof(int);
    vector<int> result=commonElements(a,b,c,n1,n2,n3);
    for(int i:result)cout<<i<<' ';
    cout<<'\n';
    return 0;
}