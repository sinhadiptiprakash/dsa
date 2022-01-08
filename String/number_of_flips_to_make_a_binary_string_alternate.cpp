#include<bits/stdc++.h>
using namespace std;
// We can solve this problem by considering all possible results, As we are supposed to get alternate string, 
// there are only 2 possibilities, alternate string starting with 0 and alternate string starting with 1. 
//We will try both cases and choose the string which will require minimum number of flips as our final answer. 
int min_filps(string str){
    int cnt1=0,cnt0=0,res;
    // first we are counting the flips if the alternate string start with 0
    // then we are counting the flips if the alternate string start with 1
    for(int i=0;i<str.length();i++){
        //starting char will be 0 so the even index should be a 0 and odd index should be 1 otherwise cnt0 increased
        if((i&1 && str[i]=='0') || (!(i&1) && str[i]=='1'))cnt0++;
        //starting char will be 1 so the even index should be a 1 and odd index should be 0 otherwise cnt1 increased
        if((i&1 && str[i]=='1') || (!(i&1) && str[i]=='0'))cnt1++;
    }
    return min(cnt0,cnt1);
}
int main(){
    string str;
    cin>>str;
    cout<<min_filps(str)<<endl;
    return 0;
}