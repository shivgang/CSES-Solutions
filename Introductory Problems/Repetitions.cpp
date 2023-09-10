#define ll long long
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){

#ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
#endif
    
    string str;
    cin>>str;

    
    int ans=1,same=1;
    for(int i=1;i<str.size();i++){
        if(str[i]==str[i-1]){
            same++;
        }else{
            same=1;
        }
        ans=max(ans,same);
    }
    
    cout<<ans<<endl;
    return 0;
}