#include <bits/stdc++.h>
using namespace std;




// -------# Short Code Defines #-----------------

#define endl '\n'

#define ll long long
#define ld long double

#define all(a) (a).begin(), (a).end()



// -------# Constants #---------------------------

#define PI 3.1415926535897932384626433832795l 
#define mod 1000000007

const int N2 = 1e2 + 5;
const int N3 = 1e3 + 5;
const int N5 = 1e5 + 5;
const int N6 = 1e6 + 5;
const int INF = 1e9 + 5;
const ll INFLL = 1e18 + 5;

const int NCRN = 1e1 + 5;
const int SIEVEN = 1e1 + 5;

vector<pair<int, int> > directions_8 {{-1, -1}, {1, 1}, {1, -1}, {-1, 1}, {0, 1}, {0, -1}, {-1, 0}, {1, 0}};
vector<pair<int, int> >directions_4 {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};




// ------# Useful Function #-----------

ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }

string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }



// -----------# Print Functions #--------------

void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

#define printv(a) {for (auto u: a) cout << u << " "; cout << endl; }




// ---------------# Debug #---------------------


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif




// ----------# Modular Arithmetic #-------------

int mul(int a, int b) { return (1ll * a * b) % mod; };
int add(int a, int b) { return (a + b) % mod; };
int sub(int a, int b) { return ((ll)a - (ll)b + (ll)mod) % mod; }
int binExp(int a, int b) { int answer = 1; while(b) { if(b & 1) answer = mul(answer, a);b >>= 1; a = mul(a, a);} return answer; };
int divi(int a, int b) { return (mul(a, binExp(b, mod - 2))); };




// ----------# Number Theory #--------------------

ll gcd(ll a, ll b) { return(b ? __gcd(a,b) : a); };
ll lcm(ll a,ll b) { return (a / gcd(a,b) * b); };



// -------------# Prime Sieve #-------------------



// -------------# Combinatorics #-----------------


int FACT[NCRN];
int IFACT[NCRN];

void ncrInit() {
    FACT[0] = 1;
    for(int i = 1; i < NCRN; i ++) FACT[i] = mul(i, FACT[i - 1]);
    IFACT[NCRN - 1] = binExp(FACT[NCRN - 1], mod - 2);
    for(int i = NCRN - 2; i >= 0; i --) IFACT[i] = mul(IFACT[i + 1], i + 1);
    return;    
}

int ncr(int n, int r) { if(r > n) return 0; return (mul(FACT[n], mul(IFACT[n - r], IFACT[r]))); };
ll ncrll(ll n, ll r) { if(r > n) return 0; if(r == 0) return 1; r = min(r, n - r); ll a = 1, b = 1; while(r) { a = a * n; b = b * r; ll int g = gcd(a, b); a /= g; b /= g; n --; r --; } return a; }

int npr(int n, int r) { if(r > n) return 0; return (mul(FACT[n], IFACT[n - r])); };
ll nprll(ll n, ll r) { if(r > n) return 0; r = min(r, n - r); if(r == 0) return 1; ll ans = 1;while(r) { ans = ans * n; n --; r --; }; return ans; }



// ----------------------------------------------

// ---------------- Precomputation ---------------




void init() {
    
    
    
    
    return;
}

// -----------------------------------------------











void solve() {
    
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    c -= a;
    d -= b;

    bool flag = true;
    if(2*a + 2 < b) flag = false;
    if(2*b + 2 < a) flag = false;
    if(2*c + 2 < d) flag = false;
    if(2*d + 2 < c) flag = false;
    
    if(flag) yes();
    else no();
    
    return;
}



int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    init();

    int t = 1;
    cin >> t;
    
    int currCase = 1;
    
    while(t --) {
        // cout << "-------# test : " << currCase << " #-------------" << endl;
        
        
        solve();
        
        currCase ++;
    }



return 0;
}

