#include <bits/stdc++.h>
using namespace std;




// -------# Short Code Defines #-----------------

#define endl '\n'

#define ll long long
#define ld long double

#define all(a) (a).begin(), (a).end()



// -------# Constants #---------------------------

#define PI 3.1415926535897932384626433832795l 
#define mod 998244353

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











void nosolve() {
    
   int n, m;
   cin >> n >> m; 

   vector<vector<int>> v(n, vector<int> (4));
   for(int i = 0; i < n; i ++) {
    for(int j = 0; j < 4; j ++) cin >> v[i][j];
   }

   map<int, vector<vector<int>>> segs;
   for(auto val: v) {
    segs[val[0] - 1].push_back({val[1] - 1, val[2], val[3]});
   }

   vector<long long> dp(m + 1, false);

   for(int i = m; i >= 0; i --) {
    if(i == m) {
        dp[i] = 1;
        continue;
    }

    if(segs.find(i) == segs.end()) continue;

    int noneProb = 1;
    for(auto seg: segs[i]) {
        noneProb = mul(noneProb, divi((seg[2] - seg[1]), seg[2]));
    }

    long long prob = 0;
    for(auto seg: segs[i]) {
        int otherNotChosenProb = mul(noneProb, divi(seg[2], sub(seg[2], seg[1]))); 
        prob = add(prob, mul(mul(divi(seg[1], seg[2]), otherNotChosenProb), dp[seg[0] + 1]));
        debug(prob);
    }

    dp[i] = prob;
   }

   debug(dp);

   cout << dp[0] << endl;
    
   return; 
}

void solve() {
    int n;
    long long m;
    std::cin >> n >> m;

    // Group segments by their starting point (0-indexed)
    // The vector stores {end_point_r, p, q}
    std::map<int, std::vector<std::vector<long long>>> segs;
    for (int i = 0; i < n; i++) {
        long long l, r, p, q;
        std::cin >> l >> r >> p >> q;
        segs[l - 1].push_back({r - 1, p, q});
    }

    // dp[i] = Probability of correctly covering the suffix of cells from i to m-1.
    std::vector<long long> dp(m + 1, 0);

    // Base Case: The probability of covering an empty strip (after cell m-1) is 1.
    dp[m] = 1;

    // Iterate backwards from the second to last cell to the first.
    for (int i = m - 1; i >= 0; i--) {
        // Check if any segments start at the current cell `i`.
        if (segs.find(i) == segs.end()) {
            // If no segment starts at `i`, cell `i` cannot be covered to start a tiling.
            // The probability of a valid covering for this suffix is 0.
            dp[i] = 0;
            continue;
        }

        const auto& starting_segs = segs.at(i);

        // --- Corrected Transition Logic (with Explanations) ---

        // 1. Calculate P_none: the probability that NONE of the segments starting at `i` are chosen.
        long long p_none = 1;
        for (const auto& seg : starting_segs) {
            long long p = seg[1];
            long long q = seg[2];
            long long prob_not_chosen = divi(sub(q, p), q);
            p_none = mul(p_none, prob_not_chosen);
        }

        // 2. Calculate the sum of weighted future probabilities.
        // To cover cell `i`, we must choose EXACTLY ONE segment.
        long long sum_of_weighted_futures = 0;
        for (const auto& seg : starting_segs) {
            long long r_idx = seg[0];
            long long p = seg[1];
            long long q = seg[2];

            // The term for this segment is (p / (q - p)) * dp[r_idx + 1]
            long long prob_ratio = divi(p, sub(q, p));
            long long future_prob = dp[r_idx + 1];
            long long term = mul(prob_ratio, future_prob);
            sum_of_weighted_futures = add(sum_of_weighted_futures, term);
        }

        // 3. Final dp[i] = P_none * Sum(...)
        dp[i] = mul(p_none, sum_of_weighted_futures);
    }

    // dp[0] contains the probability for the entire strip [0, m-1]
    std::cout << dp[0] << endl;
}



int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    init();

    int t = 1;
    // cin >> t;
    
    int currCase = 1;
    
    while(t --) {
        // cout << "-------# test : " << currCase << " #-------------" << endl;
        
        
        solve();
        
        currCase ++;
    }



return 0;
}

