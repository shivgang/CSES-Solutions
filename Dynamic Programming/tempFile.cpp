
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

vector<int> dx={-1,1,0,0};	vector<int> dy={0,0,-1,1};

void printMatrix(vector<vector<int>> &matrix){ for(auto x:matrix){ for(auto y:x){ cout<<y<<" "; } cout<<endl;}}

double logb(int a,int b){ return (double)log2(a)/ (double) log2(b);}

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr (names + 1, ',');
    cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

bool check(vector<string> &nums,int i,int j){ 
    if(i>=0 && i<nums.size() && j>=0 && j<nums[0].size() && nums[i][j]!='*') 
        return true; 
    return false;
}
int findMinPath(vector<string> &nums,int i,int j,vector<vector<int>> &dp){
    if(i<0 || j<0 || nums[i][j]=='*')  return 0;
    if(i==0 && j==0)    return 1;
    if(dp[i][j]!=-1)    return dp[i][j];
    int steps = 0;
    steps += findMinPath(nums,i,j-1,dp)%MOD;    