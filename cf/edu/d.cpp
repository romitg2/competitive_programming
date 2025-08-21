#include <bits/stdc++.h>
using namespace std;

std::vector<long long> p10(19, 1);

void precomp() {
    for (int i = 1; i < p10.size(); ++i) {
        p10[i] = p10[i - 1] * 10;
    }
}

long long sumLen(long long n) {
    if (n < 1) {
        return 0;
    }

    long long total = 0;
    long long p = 1;
    int d = 1;

    while (p * 10 <= n) {
        total += p * 9 * d;
        p *= 10;
        d++;
    }

    total += (n - p + 1) * d;
    return total;
}

long long sumDig(long long n) {
    if (n < 1) {
        return 0;
    }
    if (n < 10) {
        return n * (n + 1) / 2;
    }

    std::string s = std::to_string(n);
    int len = s.length();
    
    long long sum9s = (long long)(len - 1) * 45 * p10[len - 2];
    int msd = s[0] - '0';
    long long rem = n % p10[len - 1];

    long long total = 0;
    total += sum9s;
    total += (long long)(msd - 1) * msd / 2 * p10[len - 1];
    total += (long long)(msd - 1) * sum9s;
    total += (long long)msd * (rem + 1);
    total += sumDig(rem);

    return total;
}

void solve() {
    long long k;
    cin >> k;

    long long left = 1;
    long long right = 1e14;
    long long answer = right;

    while(left <= right) {
        long long mid = (left + right) / 2;

        long long len = sumLen(mid);
        if(len <= k) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    long long remLength = k - sumLen(answer);
    long long lastDigit = answer + 1;
    string lastDigitString = to_string(lastDigit);

    long long total = sumDig(answer);
    for(int i = 0; i < remLength; i ++) {
        total += (lastDigitString[i] - '0');
    }

    cout << total << endl;

}


int main() {
    int t;
    cin >> t;
    precomp();
    while(t --) {
        solve();
    }
}