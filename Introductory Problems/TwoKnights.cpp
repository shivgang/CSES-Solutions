#define ll long long
#define li long int
#include<iostream>
#include<bits/stdc++.h>
using namespace std;    
int main(){

#ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
#endif
    
    int n;
    cin>>n;
    cout<<0<<endl;
    for(ll i=2;i<=n;i++){
        ll total = ( i * i ) * ( i * i - 1 ) / 2;
        ll notValid = 4 * (i-1)*(i-2);
        cout<<total-notValid<<endl;
    }

    return 0;
}
    