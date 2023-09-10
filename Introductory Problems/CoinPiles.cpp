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

bool checkEqual(ll a,ll b){
    if(a==0 && b==0)    
        return true;
    if(a<=0 || b<=0)    
        return false;
    return checkEqual(a-1,b-2) || checkEqual(a-2,b-1);
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("../../input.txt","r",stdin);
    freopen("../../output.txt","w",stdout);
#endif
    
    ll t;
    cin>>t;
    while(t--){    
        ll a,b;
        cin>>a>>b;
        
        lli sum = a+b;
        if(sum % 3 == 0 && (min(a, b) * 2 >= max(a, b)))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
   
    }

    return 0;
}