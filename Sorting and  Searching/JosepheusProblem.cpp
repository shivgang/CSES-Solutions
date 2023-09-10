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

void josephus(vector<ll> A,int index,vector<ll> &order){
    cout<<"Start "<<index<<" -> ";
    if(A.size()==1){
        order.push_back(A[0]);
        A.pop_back();
        return;
    }
    
    int newindex=(index+1)%A.size();
    order.push_back(A[newindex]);
    A.erase(A.begin()+newindex);
    
    for(auto x:A)
        cout<<x<<" ";
    cout<<endl;
    josephus(A,newindex,order);

    
    
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
        A[i]=i+1;
    
    vector<ll> order;
    cout<<"done"<<endl;
    josephus(A,0,order);
    for(auto x:order)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}











