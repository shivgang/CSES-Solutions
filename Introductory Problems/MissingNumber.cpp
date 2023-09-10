#define ll long long
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){

#ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
#endif
    
    ll n;
    cin>>n;

    ll sum=0;
    vector<int> A(n-1);
    for(int i=0;i<n-1;i++){
        cin>>A[i];
        sum+=A[i];
    }
    
    cout<<(n*(n+1))/2 - sum<< endl;

    return 0;
}