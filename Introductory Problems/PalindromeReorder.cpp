#define ll long long
#define lli long long int
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

bool check(string &str){
    vector<ll> frequency(26,0);

    for(int i=0;i<str.size();i++)
        frequency[str[i]-'A']++;
    
    int one=-1;
    for(int i=0;i<26;i++){
        if(frequency[i]%2!=0){
            if(one==-1) one=i;
            else  return false;
        }
    }

    string part1,part2;
    for(int i=0;i<26;i++){
        int size=frequency[i]/2;
        while(size>0){
            part1+= i+'A';
            part2+= i+'A';
            size--;
        }    
    }
    if(one!=-1) part1+= one+'A';
    reverse(part2.begin(),part2.end());
    str=part1 + part2;
    return true;    
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("../../input.txt","r",stdin);
    freopen("../../output.txt","w",stdout);
#endif
    
    string str;
    cin>>str;
    
    if(check(str))
        cout<<str<<endl;
    else
        cout<<"NO SOLUTION"<<endl;
    return 0;
}