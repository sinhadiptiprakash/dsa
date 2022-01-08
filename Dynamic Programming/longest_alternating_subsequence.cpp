#include<bits/stdc++.h>
using namespace std;
//using dp
/*
let 
las[i][0] = Length of the longest alternating subsequence 
          ending at index i and last element is greater
          than its previous element
las[i][1] = Length of the longest alternating subsequence 
          ending at index i and last element is smaller
          than its previous element

Recursive Formulation:
   las[i][0] = max (las[i][0], las[j][1] + 1); 
             for all j < i and A[j] < A[i] 
   las[i][1] = max (las[i][1], las[j][0] + 1); 
             for all j < i and A[j] > A[i]
*/
int longestAlternatingSubsequence(vector<int> &a,int n){
    int dp[n][2];
    for(int i=0;i<n;i++){
        dp[i][0] = dp[i][1] = 1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[j]<a[i])
                dp[i][0] = max(dp[i][0], dp[j][1] + 1);
            else if(a[j]>a[i])
                dp[i][1] = max(dp[i][1], dp[j][0] + 1);
        }
    }
    return max(dp[n - 1][0], dp[n - 1][1]);
}//time complexity O(N^2) space O(N)
//below is the efficient approach
//using just two variables to optimize the time and space
int longestAlternatingSubseqenceEfficient(vector<int> &a){
    int n = a.size();
    int increament = 1, decreament = 1;
    for (int i = 1; i < n;i++){
        if(a[i]>a[i-1])
            increament = decreament + 1;
        else if(a[i]<a[i-1])
            decreament = increament + 1;
    }
    return max(increament, decreament);
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    cout << longestAlternatingSubseqenceEfficient(a) << endl;
    return 0;
}