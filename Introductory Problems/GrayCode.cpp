#define ll long long
#define lli long long int
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const lli MOD=1e9+7;

lli power(ll x,ll y){
    lli ans=1;
    while(y){
        if(y&1)
            ans=(ans*x)%MOD;
        x=(x*x)%MOD;
        y>>=1;
    }
    return ans;
}

vector<string> GrayCode(int n){
    vector<string> code={"0","1"};
    if(n==1)   
        return code;

    for(ll i=2;i<=n;i++){
        lli size=code.size();
        for(lli index=size-1;index>=0;index--)
            code.push_back(code[index]+'1');
        for(lli index=0;index<size;index++)
            code[index]+='0';
    }

    for(auto &str:code){
        reverse(str.begin(),str.end());
    }
    return code;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("../../input.txt","r",stdin);
    freopen("../../output.txt","w",stdout);
#endif
    
    ll n;
    cin>>n;
    vector<string> code=GrayCode(n);
    
    for(auto x:code){
        cout<<x<<endl;
    }

    return 0;
}