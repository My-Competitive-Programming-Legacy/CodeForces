#include <bits/stdc++.h>

using namespace std;
#define space " "
using ll =  long long int;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<vector<ll>> g(61);
    bool ok = false;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int bit = 0; bit <= 60; bit++) {
            if (((1LL << bit) & a[i]) != 0) {
                g[bit].push_back(i);
                if (g[bit].size() >= 3) {
                    ok = true;
                }
            }
        }
    }
    if (ok) {
        // cerr << "OK" << endl;
        cout << 3 << endl;
        return;
    }


    int ans = INT_MAX;


    for (int i = 0; i < n; i++) {
        if(a[i] == 0 ) continue;
        //assert(n < 200);
        queue<int> q;
        q.push(i);
        vector<int> d(n, INT_MAX), par(n);
        par[i] = -1;
        d[i] = 0;
        while (!q.empty()) {
            int cur_idx = q.front();
            q.pop();
            ll cur_val = a[cur_idx];
            for (int bit = 0; bit <= 60; bit++) {
                if ((1LL << bit) & cur_val) {
                    for (auto to_idx : g[bit]) {
                        ll to_val = a[to_idx];
                        if (d[to_idx] == INT_MAX) {
                            q.push(to_idx);
                            d[to_idx] = 1 + d[cur_idx];
                            par[to_idx] = cur_idx;
                        } else {
                            if ((par[to_idx] != cur_idx) && (par[cur_idx] != to_idx) && (cur_idx != to_idx)) {
                                ans = min(ans, 1 + d[to_idx] + d[cur_idx]);
                            }
                        }
                    }
                }
            }
        }
    }
    if (ans == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int q = 1;
    // cin >> q;
    for (int i = 1; i <= q; i++) {
        solve();
    }
}