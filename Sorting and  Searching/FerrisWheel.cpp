#define ll long long
#define lli long long int
#define lui long unsigned int
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define MOD int(1e9+7)

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

bool check(vector<vector<bool>> &grid,int i,int j){
    if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && !grid[i][j])
        return true;
    return false;
}

vector<int> dx={-1,1,0,0};
vector<int> dy={0,0,-1,1};

void concertTickets(vector<ll> &A,vector<ll> &B){
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
    vector<ll> price(m,-1);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("../../input.txt","r",stdin);
    freopen("../../output.txt","w",stdout);
#endif
    
    ll n,m;
    cin>>n>>m;

    vector<ll> A(n),B(m);
    for(ll i=0;i<n;i++) cin>>A[i];
    for(ll i=0;i<m;i++) cin>>B[i];

    concertTickets(A,B);

    return 0;
}











