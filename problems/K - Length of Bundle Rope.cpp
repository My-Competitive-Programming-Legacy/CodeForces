#include <bits/stdc++.h>

using namespace std;
#define endll '\n'
#define ar array
#define space ' '
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
const int mxN = 1e5, mxM = 1e5;
const int MOD = 1e9 + 7;
mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());


void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    set<pair<int, int>> st;
    int id = 0;
    for (int i = 0; i < n; i++) {
        st.insert({a[i], id++});
    }
    ll ans = 0;
    while (!st.empty()) {
        int sz = (int) st.size();
        if (sz == 1) {
            ans += (*st.begin()).first;
            break;
        } else if (sz == 2) {
            auto it = st.begin();
            ans += (it->first);
            it++;
            ans += it->first;
            break;
        } else {
            ll to_insert = st.begin()->first;
            st.erase(st.begin());
            to_insert += st.begin()->first;
            st.erase(st.begin());
            ans += to_insert;
            st.insert({to_insert, id++});
        }
    }
    cout << ans << endl;
}

int main() {
    IO;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}