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

// Approach 1
// void uniquePermutations1(string &s,int index,vector<string> &permutations){
//     if(index==s.size()){
//         permutations.push_back(s);
//         return;
//     }

//     unordered_map<char,int> map;
//     for (int i = index; i < s.size(); i++){
//         if(map[s[i]]==0){
//             swap(s[i],s[index]);
//             uniquePermutations1(s,index+1,permutations);
//             swap(s[i],s[index]);
//             map[s[i]]=1;    
//         }
//     }   
// }

// Approach 2
void uniquePermutations2(string &s,vector<bool> &visited,string temp,vector<string> &permutations){

    if(temp.size()==s.size()){
        permutations.push_back(temp);
        return;
    }

    for (int i = 0; i < s.size(); i++){
        if(i>0 && s[i]==s[i-1] && !visited[i-1])
            continue;           
        if(!visited[i]){
            visited[i]=true;
            // temp.push_back(s[i]);
            // uniquePermutations2(s,visited,temp,permutations);
            // temp.pop_back();             
                        // or
            uniquePermutations2(s,visited,temp+s[i],permutations);
            visited[i]=false;
        }
    }   
}




int main(){
#ifndef ONLINE_JUDGE
    freopen("../../input.txt","r",stdin);
    freopen("../../output.txt","w",stdout);
#endif
    
    string str;
    cin>>str;
    
    sort(str.begin(),str.end());
    vector<string> permutations;

    // uniquePermutations1(str,0,permutations);         // Approach 1

    vector<bool> visited(str.size(),false);
    uniquePermutations2(str,visited,"",permutations);         // Approach 2

    cout<<permutations.size()<<endl;
    sort(permutations.begin(),permutations.end());
    for(auto x:permutations)
        cout<<x<<endl;
    
    return 0;
}