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
void rounds(vector<ll> &A,int m){
    
    ll n=A.size();
    // for(int i=1;i<n;i++)
    //     cout<<A[i]<<" ";
    // cout<<endl;
    vector<ll> index(n+2);
    for(ll i=1;i<n;i++) 
        index[A[i]]=i;
    
    ll rounds=1;    
    for(ll i=2;i<n;i++){
        if(index[i] < index[i-1])   rounds++;   
    }

    // for(int i=1;i<n;i++)
    //     cout<<i<<" ";
    // cout<<endl;
    // for(int i=1;i<n;i++){
    //     cout<<index[i]<<" ";
    // }cout<<endl;
    
    // cout<<rounds<<endl;

    while(m--){
        int a,b;
        cin>>a>>b;
        int inda=A[a],indb=A[b];
        a=min(inda,indb),b=max(inda,indb);

        // cout<<"Start "<<a<<" "<<b<<endl;
        if(a>1 && index[a-1] > index[a])     
            rounds--;
        // cout<<index[a-1]<<" > "<<index[a]<<" "<<rounds<<endl;

        if(index[a+1] < index[a])     
            rounds--;
        // cout<<index[a+1] <<" < "<< index[a] <<" "<<rounds<<endl;

        if(abs(a-b)!=1 && index[b-1] > index[b])   {  
            rounds--;            
            // cout<<abs(a-b)<<"in"<<rounds<<endl;
        }
        // cout<<"exit"<<endl;

        if(b<n-1 && index[b+1] < index[b])    
            rounds--;
        // cout<<index[b+1] <<"<"<< index[b] <<" "<<rounds<<endl;

        // cout<<"swapping"<<endl;
        // cout<<a<<" "<<b<<endl;
        swap(index[a],index[b]);
        // for(int i=1;i<n;i++){
        //     cout<<index[i]<<" ";
        // }cout<<endl;
        // cout<<"After swap"<<endl;

        if(a>1 && index[a-1] > index[a])     
            rounds++;
        // cout<<index[a-1]<<" > "<<index[a]<<" "<<rounds<<endl;

        if(index[a+1] < index[a])     
            rounds++;
        // cout<<index[a+1] <<" < "<< index[a] <<" "<<rounds<<endl;

        if(abs(a-b)!=1 && index[b-1] > index[b])   {  
            rounds++;            
            // cout<<abs(a-b)<<"in"<<rounds<<endl;
        }
        // cout<<"exit"<<endl;

        if(b<n-1 && index[b+1] < index[b])    
            rounds++;
        // cout<<index[b+1] <<"<"<< index[b] <<" "<<rounds<<endl;

        // cout<<rounds<<"end"<<endl<<endl;
        cout<<rounds<<endl;
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("../../input.txt","r",stdin);
    freopen("../../output.txt","w",stdout);
#endif
    
    ll n,m;
    cin>>n>>m;

    vector<ll> A(n+1);
    for(ll i=1;i<=n;i++) cin>>A[i];
    rounds(A,m);
    // cout<<"done"<<endl;
    return 0;
}











