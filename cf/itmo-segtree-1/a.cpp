#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

// The segment tree will store the maximum LNDS length for ranges of values.
// We need two values per node:
// 1. maxValue: The maximum LNDS length found in this node's range.
// 2. lazyValue: A pending update that needs to be pushed down to children.
vector<int> maxValue;
vector<int> lazyValue;
int compressed_size;

// Pushes a pending (lazy) update from a parent node down to its children.
// This is the core of lazy propagation.
void push_down(int node) {
    if (lazyValue[node] == 0 || node * 2 + 1 >= lazyValue.size()) {
        // If there's no lazy value or this is a leaf node, do nothing.
        return;
    }

    // Apply the parent's lazy value to the children's max value.
    // The update is a 'max' operation, not an assignment.
    maxValue[node * 2] = max(maxValue[node * 2], lazyValue[node]);
    maxValue[node * 2 + 1] = max(maxValue[node * 2 + 1], lazyValue[node]);

    // Apply the parent's lazy value to the children's lazy value.
    lazyValue[node * 2] = max(lazyValue[node * 2], lazyValue[node]);
    lazyValue[node * 2 + 1] = max(lazyValue[node * 2 + 1], lazyValue[node]);

    // Reset the parent's lazy value after pushing it down.
    lazyValue[node] = 0;
}

// Performs a range maximum update on the segment tree.
// It updates the LNDS length for all values in the range [l, r].
void update(int node, int start, int end, int l, int r, int val) {
    if (start > r || end < l) {
        // No overlap
        return;
    }
    if (start >= l && end <= r) {
        // Full overlap
        maxValue[node] = max(maxValue[node], val);
        lazyValue[node] = max(lazyValue[node], val);
        return;
    }

    // Partial overlap, push down before recursing
    push_down(node);

    int mid = start + (end - start) / 2;
    update(node * 2, start, mid, l, r, val);
    update(node * 2 + 1, mid + 1, end, l, r, val);

    // Update parent's value from its children after recursion
    maxValue[node] = max(maxValue[node * 2], maxValue[node * 2 + 1]);
}

// Performs a range maximum query on the segment tree.
// It finds the maximum LNDS length for values in the range [l, r].
int query(int node, int start, int end, int l, int r) {
    if (start > r || end < l) {
        // No overlap, return a neutral value for max operation
        return 0;
    }
    if (start >= l && end <= r) {
        // Full overlap
        return maxValue[node];
    }

    // Partial overlap, push down before recursing
    push_down(node);

    int mid = start + (end - start) / 2;
    int p1 = query(node * 2, start, mid, l, r);
    int p2 = query(node * 2 + 1, mid + 1, end, l, r);

    return max(p1, p2);
}


void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> ranges(n);
    set<int> coords_set;
    for (int i = 0; i < n; ++i) {
        cin >> ranges[i].first >> ranges[i].second;
        coords_set.insert(ranges[i].first);
        coords_set.insert(ranges[i].second);
    }

    // --- Coordinate Compression ---
    // Map the large coordinate values (1 to 10^9) to smaller indices (0 to 2n-1).
    map<int, int> coord_map;
    int current_idx = 0;
    for (int val : coords_set) {
        coord_map[val] = current_idx++;
    }
    compressed_size = coord_map.size();

    // --- Segment Tree Initialization ---
    maxValue.assign(4 * compressed_size, 0);
    lazyValue.assign(4 * compressed_size, 0);

    // --- Main DP Logic ---
    for (int k = 0; k < n; ++k) {
        int l = ranges[k].first;
        int r = ranges[k].second;

        // Get compressed indices for the current range [l, r]
        int comp_l = coord_map[l];
        int comp_r = coord_map[r];

        // 1. Query: Find the max LNDS length ending with a value <= r.
        // The query range is from the very first compressed index (0) up to comp_r.
        int max_prev_lnds = query(1, 0, compressed_size - 1, 0, comp_r);
        
        // 2. Calculate: The new LNDS length we can form is 1 + the best we can extend.
        int new_lnds_length = 1 + max_prev_lnds;

        // 3. Update: We can now form an LNDS of this new length ending with any
        // value in the range [l, r]. Update the segment tree accordingly.
        update(1, 0, compressed_size - 1, comp_l, comp_r, new_lnds_length);
        
        // The answer for array length k+1 is the global maximum in the tree.
        cout << maxValue[1] << (k == n - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        cout << "-----" << endl;
        solve();
    }

    return 0;
}
