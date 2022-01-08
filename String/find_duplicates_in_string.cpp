#include<bits/stdc++.h>
using namespace std;
//using array of length 26 to count the occurences of the characters 
//assuming that the string has only lowecase letters
void find_duplicates_in_string(string s){
    int counter[26]={};
    for(int i=0;i<s.size();i++){
        counter[s[i]-'a']++;
    }
    char c='a';   
    for(int i=0;i<26;i++,c++){
        if(counter[i]>0)
            cout<<c<<" : "<<counter[i]<<endl;
    }
}
//using map
void find_duplicates_in_string2(string s){
    map<char,int> counter;
    for(char c:s){
        counter[c]++;
    }
    for(auto it:counter){
        cout<<it.first<<' '<<it.second<<endl;
    }
}
int main(){
    string s;
    cin>>s;
    find_duplicates_in_string2(s);
}