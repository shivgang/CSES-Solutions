// #define ll long long
// #define lli long long int
// #define lui long unsigned int
// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// #define MOD int(1e9+7)

// lli power(ll x,ll y){
//     lli ans=1;
//     while(y){
//         if(y&1)
//             ans=(ans*x)%MOD;
//         x=(x*x)%MOD;
//         y>>=1;
//     }
//     return ans;
// }

// bool check(vector<vector<bool>> &grid,int index,int i,int j){
//     if(i>=0 && i<7 && j>=0 && j<7 && !grid[i][j])
//         return true;
//     return false;
// }

// vector<int> dx={-1,1,0,0};
// vector<int> dy={0,0,-1,1};

// int paths=0;
// const  int n=7;
// void countPaths(vector<vector<bool>> &grid,string s,int index,int i,int j){
    
//     // cout<<index<<" "<<i<<" "<<j<<endl;
//     if(index==48 ){
//         if(i==6 && j==0){
//             // cout<<s<<endl;
//             paths++;
//             // cout<<"paths "<<paths<<endl;
//         }
//         return ;
//     }
//     if(i==6 && j==0)        // means some grids are still ungrid
//         return;
//     if (    ((j >= 1 && j <= 5 && !grid[i][j + 1] && !grid[i][j - 1]) &&
// 			((i == 0 && grid[i + 1][j]) || (i == 6 && grid[i - 1][j]))) 
// 		||
// 			((i >= 1 && i <= 5 && !grid[i + 1][j] && !grid[i - 1][j]) &&
// 				((j == 0 && grid[i][j + 1]) || (j == 6 && grid[i][j - 1]))) 
		
// 		|| (i >= 1 && i <= 5 && j >= 1 && j <= 5 && grid[i + 1][j] 
// 			&& grid[i - 1][j] && !grid[i][j + 1] && !grid[i][j - 1])
 
// 		|| (i >= 1 && i <= 5 && j >= 1 && j <= 5 && grid[i][j + 1] && grid[i][j - 1] 
// 			&& !grid[i+ 1][j] && !grid[i- 1][j]) ) 
// 	{
// 		return;
// 	}
   
//     if(s[index]!='?'){
//         grid[i][j]=true;

//         if(s[index]=='R' && check(grid,index,i,j+1))
//             countPaths(grid,s,index+1,i,j+1);

//         else if(s[index]=='L' && check(grid,index,i,j-1))
//             countPaths(grid,s,index+1,i,j-1);

//         else if(s[index]=='U' && check(grid,index,i-1,j))
//             countPaths(grid,s,index+1,i-1,j);
            
//         else if(s[index]=='D' && check(grid,index,i+1,j))
//             countPaths(grid,s,index+1,i+1,j);

//         grid[i][j]=false;
//         return;
//     }
    
//     grid[i][j]=true;
//     if(check(grid,index,i,j+1)){               // right
//         s[index]='R';
//         countPaths(grid,s,index+1,i,j+1);
//         s[index]='?';   
//     }
//     if(check(grid,index,i,j-1)){               // left   
//         s[index]='L';
//         countPaths(grid,s,index+1,i,j-1);
//         s[index]='?';   
//     }
//     if(check(grid,index,i-1,j)){               // up
//         s[index]='U';
//         countPaths(grid,s,index+1,i-1,j);
//         s[index]='?';   
//     }
//     if(check(grid,index,i+1,j)){               // down
//         s[index]='D';
//         countPaths(grid,s,index+1,i+1,j);
//         s[index]='?';
//     }
//     grid[i][j]=false;
// }

// int countPaths(string s){
//     vector<vector<bool>> grid(7,vector<bool>(7,false));
    
//     countPaths(grid,s,0,0,0);
//     return paths;
// }

// int main(){
// #ifndef ONLINE_JUDGE
//     freopen("../../input.txt","r",stdin);
//     freopen("../../output.txt","w",stdout);
// #endif
    
//     string a;
//     cin>>a;
//     // cout<< "Start" <<endl;
//     cout<< countPaths(a) <<endl;
//     // cout<< "End" <<endl;
//     return 0;
// }





















// Link to this code: https://cses.fi/paste/33e38ba5330e373238042e/
#include <bits/stdc++.h>
#include <unordered_map>
#include <time.h>
 
#define ll long long int
#define MOD 1000000007
using namespace std;
 
string s;
vector<ll> arr;
 
ll t, r, c, k, x, A, B, y, z, m, n;
 
bool isPalin(string& s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != s[s.size() - 1 - i]) {
			return false;
		}
	}
	return true;
}
 
bool isIncr(vector<ll>& a) {
	for (int i = 0; i < a.size() - 1; i++) {
		if (a[i] > a[i + 1]) {
			return false;
		}
	}
	return true;
}
 
vector<pair<int, int>> adj = { {0, 1}, {1, 0} , {0, -1}, {-1, 0} };
 
bool inBounds(int i, int j, int n, int m) {
	return (i >= 0 && i < n&& j >= 0 && j < m);
}
 
 
ll fact(ll n) {
	if (n == 0 || n == 1)
		return 1;
	else
		return n * fact(n - 1);
}
 
ll power(ll x, ll y, ll m) {
	if (y == 0)
		return 1;
	ll p = power(x, y / 2, m) % m;
	p = (p * p) % m;
 
	return (y % 2 == 0) ? p : (x * p) % m;
}
 
 
int gcd(int a, int b) {
	if (a == 0)
		return b;
	return gcd(b % a, a);
 
}
ll modInverse(ll a, ll m)
{
	ll g = gcd(a, m);
	if (g != 1)return -1;
	else
	{
		return power(a, m - 2, m);
	}
}
 
void print(vector<ll>& arr) {
	for (auto x : arr) {
		cout << x << " ";
	}
	cout << endl;
}
 
double euclid(pair<int, int>& f, pair<int, int>& s) {
	return sqrt((f.second - s.second) * (f.second - s.second) + (f.first - s.first) * (f.first - s.first));
}
 
ll sum(ll n) {
 
	ll inverse = modInverse(2, MOD);
	n = ((n % MOD) * ((n + 1) % MOD)) % MOD;
	n *= inverse;
	return n % MOD;
}
 
int numDigits(int result) {
	int ans = 0;
 
	while (result > 0) {
		ans++;
		result /= 10;
	}
	return ans;
}
 
bool visited[7][7];
int paths = 0, steps = 0;
int reserved[49];
 
void solved(int r, int c) {
 
	if (r == 6 && c == 0) {
		if (steps == 48) {
			paths++;
		}
		return;
	}
 
	if (visited[r][c] || (
		
		
			((c >= 1 && c <= 5 && !visited[r][c + 1] && !visited[r][c - 1]) &&
			((r == 0 && visited[r + 1][c]) || (r == 6 && visited[r - 1][c]))) 
		||
			((r >= 1 && r <= 5 && !visited[r + 1][c] && !visited[r - 1][c]) &&
				((c == 0 && visited[r][c + 1]) || (c == 6 && visited[r][c - 1]))) 
		
		|| (r >= 1 && r <= 5 && c >= 1 && c <= 5 && visited[r + 1][c] 
			&& visited[r - 1][c] && !visited[r][c + 1] && !visited[r][c - 1])
 
		|| (r >= 1 && r <= 5 && c >= 1 && c <= 5 && visited[r][c + 1] && visited[r][c - 1] 
			&& !visited[r + 1][c] && !visited[r - 1][c])))
	{
        // cout<<"found "<<paths<<endl;
		return;
	}
 
	visited[r][c] = true;
 
	if (reserved[steps] != -1) {
 
		switch (reserved[steps]) {
		case 0:
			if (r > 0 && !visited[r - 1][c]) {
				steps++;
				solved(r - 1, c); // up
				steps--;
			}
			break;
		case 1:
			if (r < 6 && !visited[r + 1][c]) {
				steps++;
				solved(r + 1, c);  //down
				steps--;
			}
			break;
		case 2:
			if (c > 0 && !visited[r][c - 1]) {
				steps++;
				solved(r, c - 1); //left
				steps--;
			}
			break;
		case 3:
			if (c < 6 && !visited[r][c + 1]) {
				steps++;
				solved(r, c + 1); // right
				steps--;
			}
			break;
 
		}
		
		visited[r][c] = false;
		return;
	}
 
	if (r < 6 && !visited[r + 1][c]) {
		steps++;
		solved(r + 1, c);  //down
		steps--;
	}
 
	if (r > 0 && !visited[r - 1][c]) {
		steps++;
		solved(r - 1, c); // up
		steps--;
	}
	
	if (c > 0 && !visited[r][c - 1]) {
		steps++;
		solved(r, c - 1); //left
		steps--;
	}
 
	if (c < 6 && !visited[r][c + 1]) {
		steps++;
		solved(r, c + 1); // right
		steps--;
	}
 
	visited[r][c] = false;
 
}
 
 
 
int main() {
 
	clock_t start = clock();
	ios_base::sync_with_stdio(false);
	
	cin >> s;
 
	for (int i = 0; i < s.size(); i++) {
		switch (s[i]) {
		case '?':
			reserved[i] = -1;
			break;
		case 'U':
			reserved[i] = 0;
			break;
		case 'D':
			reserved[i] = 1;
			break;
		case 'L':
			reserved[i] = 2;
			break;
		case 'R':
			reserved[i] = 3;
			break;
 
		}
	}
 
	solved(0, 0);
	cout << paths << endl;
	
	return 0;
}