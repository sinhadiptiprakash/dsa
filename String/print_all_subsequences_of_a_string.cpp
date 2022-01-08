#include<bits/stdc++.h>
using namespace std;
//the below fucntion generates all the substrings of a string using INCLUSION/EXCLUSION principle
void subSequences(string s,string output){
    //if the input string is empty we print the output stirng
    if(s.size()==0){
        cout<<output<<endl;
        return;
    }
    //we are making a string without the first character
    string rest=s.substr(1);
    //calling recursively including the first character in the result
    subSequences(rest,output+s[0]);
    //calling recursively excluding the first character in the result
    subSequences(rest,output);
}
//below is the another approach using recursion
vector<string> sub_sequences(string str,int n){
    //there is no subset of an empty string
    if(n==0)
        return {""};
    // we are finding the subsets for the n-1 characters of the string
    auto res_rest=sub_sequences(str,n-1);
    // storing the size of the res because we will push more string into it so the size of the res will be increased
    int res_size=res_rest.size();
    //now in along with the subsets of the n-1 characters we will push each substring+the last character into the res
    for(int i=0;i<res_size;i++){
        res_rest.push_back(res_rest[i]+str[n-1]);
    }
    return res_rest;
}
int main(){
    auto res=sub_sequences("abc",3);
    for(auto it:res){
        cout<<it<<endl;
    }
    return 0;
}