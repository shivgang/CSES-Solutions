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

ll maxSum(vector<ll> &A){
    ll n=A.size();
    
    ll sum=INT_MIN,temp=0;
    for(int i=0;i<n;i++){
        temp+=A[i];
        sum=max(sum,temp);
        if(temp<0)  temp=0;
    }

    return sum;
    
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
    
    cout<<maxSum(A)<<endl;

    return 0;
}











