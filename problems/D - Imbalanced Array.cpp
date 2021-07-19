#include <bits/stdc++.h>

using namespace std;
#define space " "
using ll =  long long int;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    stack<pair<int, int>> st;
    vector<int> L(n), R(n);
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top().first <= a[i]) { // check the equality
            st.pop();
        }
        int idx = n - 1;
        if (!st.empty()) {
            idx = st.top().second - 1;
        }
        st.push({a[i], i});
        R[i] = idx - i;
    }
    while (!st.empty()) st.pop();
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top().first < a[i]) { // only one should be equal for reptition :)
            st.pop();
        }
        int idx = 0;
        if (!st.empty()) {
            idx = st.top().second + 1;
        }
        st.push({a[i], i});
        L[i] = (i - idx);
    }
//    for (auto v : L) {
//        cerr << v << space;
//    }
//    cerr << endl;
//    for (auto v : R) {
//        cerr << v << space;
//    }
//    cerr << endl;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (L[i] + 1) * 1LL * (R[i] + 1) * 1ll * a[i] ;
    }
    // Second tour
    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top().first >= a[i]) {
            st.pop();
        }
        int idx = n - 1;
        if (!st.empty()) {
            idx = st.top().second - 1;
        }
        st.push({a[i], i});
        R[i] = idx - i;
    }
    while (!st.empty()) st.pop();
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top().first > a[i]) {
            st.pop();
        }
        int idx = 0;
        if (!st.empty()) {
            idx = st.top().second + 1;
        }
        st.push({a[i], i});
        L[i] = i - idx;
    }
//    for (auto v : L) {
//        cerr << v << space;
//    }
//    cerr << endl;
//    for (auto v : R) {
//        cerr << v << space;
//    }
//    cerr << endl;
    for (int i = 0; i < n; i++) {
        ans -= (L[i] + 1) * 1ll * (R[i] + 1) * a[i];
    }
    cout << ans << endl;
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