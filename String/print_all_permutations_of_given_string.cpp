#include<bits/stdc++.h>
using namespace std;
vector<string> permutation(string str){
    if(str.length()==1)return {str};
    vector<string> all;
    for(int i=0;i<str.length();i++){
        string rem=str.substr(0,i)+str.substr(i+1,str.length()-(i+1));
        vector<string> remaining=permutation(rem);
        for(string s:remaining)all.push_back(str[i]+s);
    }
    return all;
}
int main(){
    string str;
    cin>>str;
    auto res=permutation(str);
    return 0;
}