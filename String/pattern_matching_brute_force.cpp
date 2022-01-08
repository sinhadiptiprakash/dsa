#include <bits/stdc++.h>
using namespace std;
// returns a vector of multiple indexes where the pattern matches
vector<int> pattern_matching_brute_force(string str,string pattern){
    int n=str.size();
    int m=pattern.size();
    vector<int> indexes;
    for(int i=0;i<=n-m;i++){
        bool flg=true;
        //for pattern searching
        for(int j=0;j<m;j++){
            if(pattern[j]!=str[i+j])
                flg=false;
        }
        if(flg)indexes.push_back(i);
    }
    return indexes;
}
int main(){
    string str,pattern;
    cin>>str>>pattern;
    auto res=pattern_matching_brute_force(str,pattern);
    cout<<"pattern found at the following indexes"<<endl;
    for(int i:res)cout<<i<<' ';
    cout<<endl;
    return 0;
}