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




class SegmentTree {
private:
    std::vector<int> tree; // The array that stores the segment tree nodes
    std::vector<int> data; // The original input data array
    int n;                 // The number of elements in the original data

    /**
     * @brief Recursively builds the segment tree.
     * @param node The index of the current node in the `tree` vector.
     * @param start The starting index of the segment represented by this node.
     * @param end The ending index of the segment represented by this node.
     */
    void _build(int node, int start, int end) {
        // Base case: If the segment has only one element (a leaf node).
        if (start == end) {
            tree[node] = data[start];
            return;
        }

        // Recursive step:
        int mid = start + (end - start) / 2; // Avoids potential overflow
        int left_child = 2 * node;
        int right_child = 2 * node + 1;

        // Build the left and right subtrees.
        _build(left_child, start, mid);
        _build(right_child, mid + 1, end);

        // The value of the internal node is the maximum of its children.
        tree[node] = std::max(tree[left_child], tree[right_child]);
    }

    /**
     * @brief Recursively performs the range maximum query.
     * @param node Current node's index in the tree vector.
     * @param start Start index of the current node's segment.
     * @param end End index of the current node's segment.
     * @param l Start index of the query range.
     * @param r End index of the query range.
     * @return The maximum value in the query range.
     */
    int _query(int node, int start, int end, int l, int r) {
        // Case 1: The node's range is completely outside the query range.
        if (start > r || end < l) {
            return std::numeric_limits<int>::min(); // Return a very small number
        }

        // Case 2: The node's range is completely inside the query range.
        if (l <= start && end <= r) {
            return tree[node];
        }

        // Case 3: The node's range partially overlaps with the query range.
        int mid = start + (end - start) / 2;
        int left_query = _query(2 * node, start, mid, l, r);
        int right_query = _query(2 * node + 1, mid + 1, end, l, r);

        return std::max(left_query, right_query);
    }

    /**
     * @brief Recursively updates a value in the tree.
     * @param node Current node's index in the tree vector.
     * @param start Start index of the current node's segment.
     * @param end End index of the current node's segment.
     * @param idx The index in the original data array to update.
     * @param val The new value.
     */
    void _update(int node, int start, int end, int idx, int val) {
        // Base case: We've reached the leaf node corresponding to the index.
        if (start == end) {
            data[idx] = val;
            tree[node] = val;
            return;
        }

        // Recursive step:
        int mid = start + (end - start) / 2;
        if (start <= idx && idx <= mid) {
            // Index is in the left child's range.
            _update(2 * node, start, mid, idx, val);
        } else {
            // Index is in the right child's range.
            _update(2 * node + 1, mid + 1, end, idx, val);
        }

        // After updating a child, update the parent node's value.
        tree[node] = std::max(tree[2 * node], tree[2 * node + 1]);
    }

public:
    /**
     * @brief Constructs the Segment Tree.
     * @param arr The input data vector.
     */
    SegmentTree(const std::vector<int>& arr) {
        if (arr.empty()) {
            throw std::invalid_argument("Input data cannot be empty.");
        }
        data = arr;
        n = arr.size();
        // Allocate 4*n space for the tree for safety.
        tree.resize(4 * n); 
        // Start the build process from the root (node 1).
        _build(1, 0, n - 1);
    }

    /**
     * @brief Public method for a range maximum query.
     * @param l The starting index of the query range (inclusive).
     * @param r The ending index of the query range (inclusive).
     * @return The maximum value in the given range.
     */
    int query(int l, int r) {
        if (l < 0 || r >= n || l > r) {
            throw std::out_of_range("Query range is out of bounds.");
        }
        return _query(1, 0, n - 1, l, r);
    }

    /**
     * @brief Public method to update a value at a specific index.
     * @param idx The index in the original data array to update (0-based).
     * @param val The new value.
     */
    void update(int idx, int val) {
        if (idx < 0 || idx >= n) {
            throw std::out_of_range("Update index is out of bounds.");
        }
        _update(1, 0, n - 1, idx, val);
    }
};





void solve() {
    
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];

    vector<int> init((int)3e5 + 5, 0);
    
    SegmentTree st(init);
    int answer = 0; 

    for(int i = 0; i < n; i ++) {
        int left = max(0, a[i] - k);
        int right = min(3e5, a[i] + k);

        int currAnswer = st.query(left, right) + 1;
        answer = max(answer, currAnswer);

        st.update(a[i], currAnswer);
    }

    cout << answer << endl;

    return;    
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

