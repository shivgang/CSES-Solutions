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


// Memorized dp solution TLE
// ll coinCombinationsII(vector<int> &A,int index,int sum,vector<vector<int>> &dp){
//     if(sum==0)  
//         return 1;
//     if(index==A.size()) 
//         return 0;

//     if(dp[index][sum]!=-1) 
//         return dp[index][sum];

//     ll notIncluded= coinCombinationsII(A,index+1,sum,dp)%MOD;

//     ll included= 0;
//     if(sum>=A[index])
//         included= coinCombinationsII(A,index,sum-A[index],dp)%MOD ;
    
//     return dp[index][sum]=(included + notIncluded)%MOD;
// }

// Tabultated dp solution 2D
// ll coinCombinationsII(vector<int> &A,int index,int sum){
//     ll n=A.size();
    
//     vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
//     for(int i=0;i<=n;i++)    dp[i][0]=1;

//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=sum;j++){
//             dp[i][j]=dp[i-1][j];
//             if(j>=A[i-1])
//                 dp[i][j] += dp[i][j-A[i-1]]%MOD ;
//             dp[i][j]%=MOD;
//         }
//     }
    
    
//     return dp[n][sum]%MOD;
// }

// Tabulated dp solution 1 d
ll coinCombinationsII(vector<int> &A,int sum){
    ll n=A.size();
    
    vector<ll> dp(sum+1,0);
    dp[0]=1;

    for(int i=0;i<n;i++){
        for(int j=1;j<=sum;j++){
            if(j>=A[i]){
                dp[j]+=dp[j-A[i]];
                dp[j]%=MOD;
            }
        }
    }
    
    
    return dp[sum]%MOD;
}

// ll coinCombinationsII(vector<int> &A,int index,int &sum,vector<ll> &dp){
    
//     if(index==A.size()) return 0;
    
//     for(int j=1;j<=sum;j++){
//         if(j>=A[index]){
//                 dp[j]+= coinCombinationsII(A,index+1,);
//                 dp[j]%=MOD;
//         }
//     }
    
//     return dp[j]%MOD;
// }

int main(){
#ifndef ONLINE_JUDGE
    freopen("./input.txt","r",stdin);
    freopen("./output.txt","w",stdout);
#endif
    int n,x;
    cin>>n>>x;  

    vector<int> A(n);
    for(int i=0;i<n;i++)    cin>>A[i];
    sort(A.begin(),A.end());
    
    // vector<vector<int>> dp(n,vector<int>(x+1,-1));
    // vector<ll> dp(x+1,0);
    // dp[0]=1;
    // ll coins=coinCombinationsII(A,0,dp);

    ll coins=coinCombinationsII(A,x);
    cout<<coins<<endl;
        
    return 0;
}











