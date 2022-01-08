#include<bits/stdc++.h>
using namespace std;
//recursive approach 
string remove_duplicates(string s){
    if(s.size()<2)return s;
    char last=s.back();
    s.pop_back();
    string temp=remove_duplicates(s);
    if(temp.back()==last)return temp;
    else return temp+last;
}//time complexity O(N) space complexity O(N) for recursive stack
//below is the efficient approach
string remove_duplicates2(string s){
    int n=s.size();
    if(n<2)return s;
    int j=0;
    string res="";
    res+=s[0];
    for(int i=1;i<n;i++){
        if(s[i]!=s[i-1])
            res.push_back(s[i]);
    }
    return res;
}//time complexity O(N) space complexity O(1)
int main(){
    string s;
    cin>>s;
    auto res=remove_duplicates2(s);
    cout<<res<<endl;
    return 0;
}