/*
    ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् |
    उर्वारुकमिव बन्धनान्मृत्योर्मुक्षीय माऽमृतात् ||
*/

#include<bits/stdc++.h>
using namespace std;


#define ll             long long
#define int	           long long int
#define lu             long unsigned int32_t
#define F              first
#define S              second
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define endl           "\n"
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define double         long double
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl
#define sortv(a)       sort(a.begin(),a.end())
#define sorta(a,n)       sort(a,a+n)
#define PI   3.1415926535897932384626433832795

#define MOD             int32_t(1e9+7)
const  int N = 2e5+7;

inline int power(int x,int y){ int ans=1; while(y){ if(y&1) ans=(ans*x)%MOD; x=(x*x)%MOD; y>>=1;} return ans;}

inline int charToDigit(char ch){ return ch - '0'; }
inline char digitToChar(int digit){ return digit +'0'; }
string add(const string &a,const string &b){ int n = a.size() , m = b.size(); string s; int i = n-1 , j = m-1 , carry = 0; for(;i>=0 || j>=0;){ int number = carry; carry = 0; if (i>=0)   number += charToDigit(a[i--]); if (j>=0)   number += charToDigit(b[j--]); carry = number/10; number%=10; s+= digitToChar(number);	} if(carry>=1) s+=to_string(carry); reverse(s.begin(),s.end()); return s;}

// multiplies a big int in the form of vector with a number
void multiply(vector<int> &fact,int number,int &size){  int carry = 0;  for(int i=0;i<size;i++){ int prod = fact[i] * number + carry; fact[i] = prod%10; carry = prod/10; } while(carry){ fact[size] = carry%10; carry/=10; size++; } }

// computes factorial of a number and prints
void computeFactorial(int n){ vector<int> fact(1000,0); fact[0]=1; int size = 1; for(int i=2;i<=n;i++) multiply(fact,i,size);  for(int i=size-1;i>=0;i--)  cout<<fact[i];  cout<<endl;}

vector<bool> sieve(int n){ vector<bool> prime(n+1,true); prime[0] = false;prime[1] = false; for(int i=2;i<=n;i++){ if(prime[i]){ for(int j=i*i;j<=n;j+=i) prime[j] = false; } }  return prime; }
// performs binary multiplication and avoids overflow of multiplication of very big ints
int binaryMultiplication(int a,int b,int mod){ int res = 0; while(b){ if(b&1) res = (res + a)%mod; a = (2*a)%mod; b>>=1; } return res; }

int gcd(int a,int b){ if(a%b==0)  return b; return gcd(b,a%b); }
void computelps(string s,int *lps){
    lps[0] = 0;     // lps of a single character is always 0
    int len = 0 , i = 1;
    while(i<s.size()){if(s[i]==s[len]){           // if characters equal we can simply add this chaaracter
            len++;                  // to previously compute array lps
            lps[i] = len; i++;
        }else{  if(len==0)  lps[i++] = 0;       // if len becomes 0 no lps exists
            else    len =  lps[len-1];      // reduce len so as to find lps in smaller subarray
        }
    }
}   
int kmp(string haystack, string needle) {int n = haystack.size();int m = needle.size();int *lps = new int[m]{0};computelps(needle,lps);int i = 0 , j = 0;while(n-i>=m-j){if(haystack[i] == needle[j]){i++;j++;if(j==m)    return i - m ;}else{if(j==0)    i++;else j = lps[j-1];}}return -1;}

int rabinKarp(string source, string target) { int n = source.size() , m = target.size(); int d = 31; int q = int32_t(1e9+7); int preCompute = 1; for(int i=1;i<m;i++){ preCompute *= d ; preCompute %= q; } int hsource = 0 , htarget = 0; for(int i=0;i<m;i++){ hsource  = (hsource*d + source[i])%q; htarget  = (htarget*d + target[i])%q; } if(hsource == htarget && source.substr(0,m)==target)    return 0;     for(int i=m;i<n;i++){ hsource = (hsource - preCompute*source[i-m])%q; hsource = (hsource*d + source[i])%q; if(hsource<0)    hsource+=q; if(hsource==htarget && source.substr(i-m+1,m)==target)  return i - m + 1; } return -1; }

bool check(vector<vector<bool>> &grid,int i,int j){ if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && !grid[i][j]) return true; return false; }

vector<int> dx={-1,1,0,0};	vector<int> dy={0,0,-1,1};

void printMatrix(vector<vector<int>> &matrix){ for(auto x:matrix){ for(auto y:x){ cout<<y<<" "; } cout<<endl;}}

double logb(int a,int b){ return (double)log2(a)/ (double) log2(b);}

// vector<int> rotatedIs = { i, n-1-j, n-1-i , j};
// vector<int> rotatedJs = { j, i    , n-1-j, n-1-i};
template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr (names + 1, ',');
    cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

class SegmentTree{
    vector <int> nodes ;
    vector <int> lazy ;
    vector <int> nums;
    vector <int> setVal;

    int n ;
    void build(int low , int high , int node){
        if (low == high){
            nodes [node] = nums [low];
            return;
        }
        int mid = low + (high - low) / 2;
        build (low , mid , 2 * node);
        build (mid + 1 , high , 2 * node + 1);

        nodes [node] = nodes [2 * node] + nodes [2 * node + 1];
    }
    int query (int qlow , int qhigh , int l , int r , int node){
        if (setVal [node] != 0){
            nodes [node] = (r - l + 1) * setVal [node];
            if (l != r){
                lazy [2 * node] = 0 ;
                lazy [2 * node + 1] = 0 ;
                setVal [2 * node] = setVal [node];
                setVal [2 * node + 1] = setVal [node];
            }
            setVal [node] = 0;
        }
        if ( lazy [node] != 0 ){
            nodes [node] += (r - l + 1) * lazy [node];
            if ( l != r ) {
                lazy [2 * node] += lazy [node];
                lazy [2 * node + 1] += lazy [node];
            }
            lazy [node] = 0;
        }
        if ( qlow > r || qhigh < l )  return 0;
        if ( qlow <= l && r <= qhigh )    return nodes [node];

        int mid = l + ( r - l )/2;
        int left = query ( qlow , qhigh , l , mid , 2 * node );
        int right = query ( qlow , qhigh , mid + 1 , r , 2 * node + 1 );
        
        return left + right ;
    }

    void update (int qlow , int qhigh , int val , int l , int r , int node){
        if (setVal [node] != 0){
            nodes [node] = (r - l + 1) * setVal [node];
            if (l != r){
                lazy [2 * node] = 0 ;
                lazy [2 * node + 1] = 0 ;
                setVal [2 * node] = setVal [node];
                setVal [2 * node + 1] = setVal [node];
            }
            setVal [node] = 0;
        }
        if ( lazy [node] != 0 ){
            nodes [node] +=  (r - l + 1) * lazy [node];
            if ( l != r ) {
                lazy [2 * node] += lazy [node];
                lazy [2 * node + 1] += lazy [node];
            }
            lazy [node] = 0;
        }
        if ( qlow > r || qhigh < l )  return;
        if ( qlow <= l && r <= qhigh ){
            nodes [node] += (r - l + 1) * val;
            
            if ( l != r ) {
                lazy [2 * node] += val ;
                lazy [2 * node + 1] += val ;
            }
            return;
        }
        
        int mid = l + ( r - l )/2;
        
        update ( qlow , qhigh , val , l , mid , 2 * node );
        update ( qlow , qhigh , val , mid + 1 , r , 2 * node + 1 );
        
        nodes [node] = nodes [ 2 * node] + nodes [2 * node + 1];
    }

    void assign(int qlow , int qhigh , int val , int l , int r , int node){
        if (setVal [node] != 0){
            nodes [node] = (r - l + 1) * setVal [node];
            if (l != r){
                lazy [2 * node] = 0 ;
                lazy [2 * node + 1] = 0 ;
                setVal [2 * node] = setVal [node];
                setVal [2 * node + 1] = setVal [node];
            }
            setVal [node] = 0;
        }
        if ( lazy [node] != 0 ){
            nodes [node] +=  (r - l + 1) * lazy [node];            
            if ( l != r ) {
                lazy [2 * node] += lazy [node];
                lazy [2 * node + 1] += lazy [node];
            }
            lazy [node] = 0;
        }
        if ( qlow > r || qhigh < l ){  
            return;
        }
        if ( qlow <= l && r <= qhigh ){
            nodes [node] = (r - l + 1) * val;

            if ( l != r ) {
                lazy [2 * node] = 0 ;
                lazy [2 * node + 1] = 0 ;
                setVal [2 * node] = val ;
                setVal [2 * node + 1] = val ;
            }
            return;
        }
        
        int mid = l + ( r - l )/2;
        
        assign ( qlow , qhigh , val , l , mid , 2 * node );
        assign ( qlow , qhigh , val , mid + 1 , r , 2 * node + 1 );
        
        nodes [node] = nodes [ 2 * node] + nodes [2 * node + 1];
    }
public:
    SegmentTree (const vector <int> &nums){
        this -> nums = nums;
        this -> n = nums.size ();
        this -> lazy . resize ( 4 * n );
        this -> nodes . resize ( 4 * n );
        this -> setVal . resize (4 * n , 0);
        build (0 , n - 1 , 1);
    }
    void update (int low , int high , int val){
        update (low , high , val , 0 , n - 1 , 1 );
    }
    int query (int low , int high){
        return query (low , high , 0 , n - 1 , 1 );
    }
    void printTree(){
        for ( auto x : nodes ){
            cout << x <<" ";
        }cout << endl;
    }
    void assign(int low , int high , int val){
        assign (low , high , val , 0 , n - 1 , 1);
    }
};


void solve() {
    int n , q;
    cin >> n >> q;
    
    vector <int> nums (n + 1);
    for(int i = 1 ; i <= n ; i++){
        cin >> nums [i];
    }

    SegmentTree segment (nums);

    while(q--){
        int type;
        cin >> type;
        if (type == 1){
            int a , b , x;
            cin >> a >> b >> x;
            segment.update (a , b , x);
        }else if (type == 2){
            int a , b , x;
            cin >> a >> b >> x;
            segment.assign (a , b , x);
        }else{
            int a , b;
            cin >> a >> b;
            cout << segment.query (a , b) << endl;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// cout.precision(7); cout.setf(ios::fixed);
#ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
#endif

    clock_t z = clock();

    int t = 1;
    // cin >> t;
    while (t--) solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}