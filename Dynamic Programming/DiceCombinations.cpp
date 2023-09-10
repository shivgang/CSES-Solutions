#define ll long long
#define lli long long int
#define lui long unsigned int
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define MOD int(1e9+7)

const  ll N = 2e5+7;
#define PI   3.1415926535897932384626433832795

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

bool check(vector<vector<bool>> &grid,int index,int i,int j){
    if(i>=0 && i<7 && j>=0 && j<7 && !grid[i][j])
        return true;
    return false;
}

vector<int> dx={-1,1,0,0};
vector<int> dy={0,0,-1,1};

int diceCombinations(int n,vector<int> &dp){
    if(n==0)    return 1;
    if(dp[n]!=-1)   return dp[n];
    // cout<<n<<endl;
    ll comb=0;
    for(int i=6;i>=1;i--){
        if(i<=n){
            comb+=diceCombinations(n-i,dp) % MOD;
            comb%=MOD;
        }
    }
    return dp[n]=comb%MOD;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("../../input.txt","r",stdin);
    freopen("../../output.txt","w",stdout);
#endif
    int n;
    cin>>n;
    // cout<<n<<endl;
    vector<int> dp(n+1,-1);
    cout<<diceCombinations(n,dp)<<endl;
    // cout<<n<<endl;
    return 0;
}











