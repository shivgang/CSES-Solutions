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

int main(){

#ifndef ONLINE_JUDGE
    freopen("../../input.txt","r",stdin);
    freopen("../../output.txt","w",stdout);
#endif
    
    ll n;
    cin>>n;
    cout<<power(2,n)<<endl;

    // cout<<pow(2,n)<<endl;
    
    return 0;
}