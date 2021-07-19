#include <bits/stdc++.h>

using namespace std;
#define endll '\n'
#define ar array
#define space ' '
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
const int mxN = 1e5, mxM = 1e5;
const int MOD = 1e9 + 7;


void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    int ans = INT_MAX;
    for (int i = 0; i < (1 << m); i++) {
        vector<int> cnt(n, 0);
        for (int j = 0; j < m; j++) {
            if ((1 << j) & i) {
                for (int k = 0; k < n; k++) {
                    int bit = (a[j][k] == '1');
                    cnt[k] = (cnt[k] | bit);
                }
            }
        }
        bool ok = true;
        for (auto v : cnt) {
            if (!v) {
                ok = false;
            }
        }
        if (ok) {
            ans = min(ans, __builtin_popcount(i));
        }
    }
    if(ans == INT_MAX) ans = -1 ;
    cout<< ans <<endl;

}

int main() {
    IO;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}