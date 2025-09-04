#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

string w1, w2, w3;
vector<char> l;
set<char> lc;

map<char, int> m;
vector<bool> u(10, false);

long long val(const string& w) {
    long long res = 0;
    for (char c : w) {
        res = res * 10 + m[c];
    }
    return res;
}

int dfs() {
    if (m.size() == l.size()) {
        return (val(w1) + val(w2) == val(w3));
    }

    char cur = ' ';
    for (char c : l) {
        if (m.find(c) == m.end()) {
            cur = c;
            break;
        }
    }

    int sol = 0;
    for (int d = 0; d < 10; ++d) {
        if (u[d]) continue;
        if (d == 0 && lc.count(cur)) continue;

        m[cur] = d;
        u[d] = true;
        sol += dfs();
        u[d] = false;
        m.erase(cur);
    }
    
    return sol;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> w1 >> w2 >> w3;

    set<char> s;
    s.insert(w1.begin(), w1.end());
    s.insert(w2.begin(), w2.end());
    s.insert(w3.begin(), w3.end());

    l.assign(s.begin(), s.end());
    
    if (w1.length() > 1) lc.insert(w1[0]);
    if (w2.length() > 1) lc.insert(w2[0]);
    if (w3.length() > 1) lc.insert(w3[0]);
    
    cout << dfs() << endl;
    
    return 0;
}