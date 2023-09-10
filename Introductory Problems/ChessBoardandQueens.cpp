#define ll long long
#define lli long long int
#define lui long unsigned int
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const lli MOD=1e9+7;

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


// wont work this method for large testcases where sum is quite large and hence dp table is not getting created
// ll minimumDifference(vector<ll> &A){

//     lui n=A.size();

//     lli sum=0;
//     for(lli i=0;i<n;i++)    sum+=A[i];

//     vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));

    // cout<<sum<<endl;
    // for(lli i=0;i<=n;i++)
    //     dp[i][0]=true;
    
    // for(lli i=1;i<=n;i++){
    //     for(lli j=1;j<=sum;j++){
    //         dp[i][j]=dp[i-1][j];
    //         if(j>=A[i-1]){
    //             dp[i][j]=dp[i][j] || dp[i-1][j-A[i-1]];
    //         }
    //     }
    // }

    // lli diff=sum;
    // for(lli j=1;j<=sum;j++){
    //     if(dp[n][j])
    //         diff=min(diff,abs(2*j - sum));
    // }

    // return diff;
//     return 0;
// }

void minimumDifference(vector<ll> &A,ll index,lli &totsum,lli sum,ll &mini){
    if(index<0){
        mini=min(mini,abs(sum-(totsum-sum)));
        return;
    }
    minimumDifference(A,index-1,totsum,sum+A[index],mini);
    minimumDifference(A,index-1,totsum,sum,mini);
}

ll minimumDifference(vector<ll> &A){
    lli n=A.size(),sum=0;
    for(int i=0;i<n;i++)    sum+=A[i];
    
    ll mini=sum;
    minimumDifference(A,n-1,sum,0,mini);
    return mini;
}

bool check(vector<string> &board,int x,int y){
    if(board[x][y]=='*')
        return false;
    for(int i=0;i<=x;i++){
        if(board[i][y]=='Q')    return false;
        if(board[i][y]=='*')    break;
    }

    int i=x,j=y;
    while(i>=0 && j>=0){
        if(board[i][j]=='*')    break;
        if(board[i][j]=='Q')    return false;
        i--;j--;
    }

    i=x,j=y;
    while(i>=0 && j<8){
        if(board[i][j]=='*')    break;
        if(board[i][j]=='Q')    return false;
        i--;j++;
    }

    return true;
}

void countWays(vector<string> &board,int i,int j,ll ans){
    if(i==8){    
        ans++;
        return;
    }
    if(j==8){ 
        i++;j=0;
    }
    cout<<i<<" "<<j<<endl;
    if(check(board,i,j)){
        board[i][j]='Q';
        countWays(board,i,j+1,ans);
        board[i][j]='.';
    }else
        countWays(board,i,j+1,ans);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("../../input.txt","r",stdin);
    freopen("../../output.txt","w",stdout);
#endif
    
    int n=8;

    vector<string> board(8);
    for(int i=0;i<8;i++)
        cin>>board[i];

    ll ans=0;
    countWays(board,0,0,ans);
    cout<<ans<<endl;

    return 0;
}