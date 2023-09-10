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

void findValues(vector<pair<ll,ll>> &A,ll x){
    ll n=A.size();
    sort(A.begin(),A.end());

    pair<ll,ll> ans;
    ans.first=-1;

    for(int i=0,j=n-1;i<j;){
        if(A[i].first+A[j].first==x){
            ans.first=min(A[i].second,A[j].second);
            ans.second=max(A[i].second,A[j].second);
            break;
        }else if(A[i].first+A[j].first < x)
            i++;
        else j--;
    }

    if(ans.first==-1)   cout<<"IMPOSSIBLE"<<endl;
    else    cout<<ans.first<<" "<<ans.second<<endl;
    
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("../../input.txt","r",stdin);
    freopen("../../output.txt","w",stdout);
#endif
    
    ll n,x;
    cin>>n>>x;

    vector<pair<ll,ll>> A(n);
    for(ll i=0;i<n;i++) {
        cin>>A[i].first;
        A[i].second=i+1;
    }
    findValues(A,x);

    return 0;
}











