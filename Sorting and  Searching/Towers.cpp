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

ll towers(vector<ll> &A){

    ll n=A.size();
    // sort(A.begin(),A.end());
    
    vector<ll> towers={A[0]};
    for(int i=1;i<n;i++){

        int index= upper_bound(towers.begin(),towers.end(),A[i]) - towers.begin();
        if(index==towers.size())
            towers.push_back(A[i]);
        else
            towers[index]=A[i];
        // for(auto x:towers){
        //     cout<<x<<" ";
        // }cout<<endl;
    }

    return towers.size();
    
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
    
    cout<<towers(A)<<endl;

    return 0;
}











