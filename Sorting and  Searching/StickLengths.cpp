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

bool cmp(const pair<ll,ll> &a,const pair<ll,ll> &b){
    if(a.second==b.second)  
        return a.first<b.first;
    return a.second<b.second;
}

ll length(vector<ll> &A){
    ll n=A.size();

    sort(A.begin(),A.end());
    ll cost=0,median=A[n/2];
    for(int i=0;i<n;i++){
        cost+=abs(A[i]-median);
    }

    return cost;
    
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("../../input.txt","r",stdin);
    freopen("../../output.txt","w",stdout);
#endif
    
    ll n;
    cin>>n;

    vector<ll> A(n);
    for(ll i=0;i<n;i++) 
        cin>>A[i];
    
    cout<<length(A)<<endl;

    return 0;
}










