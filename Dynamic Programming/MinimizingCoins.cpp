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

ll minimizeCoins(vector<int> &A,int sum,vector<int> &dp){
    if(sum==0)  return 0;
    if(dp[sum]!=-1) return dp[sum];

    ll mini=INT_MAX;
    for(int i=0;i<A.size();i++){
        if(A[i]<=sum){
            mini=min(mini,minimizeCoins(A,sum-A[i],dp)+1);
        }
    }
    return dp[sum]=mini;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("../../input.txt","r",stdin);
    freopen("../../output.txt","w",stdout);
#endif
    int n,l;
    cin>>n>>l;  

    vector<int> A(n);
    for(int i=0;i<n;i++)    cin>>A[i];

    vector<int> dp(l+1,-1);
    ll coins=minimizeCoins(A,l,dp);

    if(coins==INT_MAX)
        cout<<-1<<endl;
    else
        cout<<coins<<endl;
        
    return 0;
}











