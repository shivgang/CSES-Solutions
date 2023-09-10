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
    
    lli count=0;
    for(lli i=5;n/i>=1;i*=5){
        count+=n/i;
    }
    cout<<count<<endl;
    
    return 0;
}