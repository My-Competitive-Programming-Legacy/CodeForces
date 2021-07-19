#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define ar array
#define space " "
#define pb push_back
#define vi vector<int>
#define vii vector<vector<int>>
const double inf = 2e18;
#define EPS  0.0000000001

struct Point {
    int L, R, idx;
    bool operator<(Point &o) {
        return make_pair(L, -1 * R) < make_pair(o.L, -1 * o.R);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<Point> a(n);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        a[i] = {l, r, i + 1};
    }
    set<pair<int, int>> st;
    sort(a.begin(), a.end());
    for (int i = n - 1; i >= 0; i--) {
        int R = a[i].R;
        if ((!st.empty()) && st.begin()->first <= R) {
            cout <<  (st.begin()->second) << space << a[i].idx <<endl;
            return ;
        }
        st.insert({a[i].R, a[i].idx});
    }
    cout <<-1 <<space << -1 <<endl;

}

int main() {
    int q = 1;
//    cin >> q;
    while (q--) {
        solve();
    }


}