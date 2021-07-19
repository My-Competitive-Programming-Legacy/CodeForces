#include <bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define vii vector<vector<int>>
#define ld long


const int mxN = 103;
int query = 1;

void solve() {
    int n;
    cin >> n;
    vector<pair<ll, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    vector<bool> can(n, false);
    vector<ll> pre(n);
    pre[0] = a[0].first;
    for (int i = 1; i < n; i++) {
        pre[i] = a[i].first + pre[i - 1];
    }
    int cnt = 0;
    can[a[n - 1].second] = true;
    for (int i = n - 2; i >= 0; --i) {
        if (pre[i] >= a[i + 1].first && can[a[i+1].second]) {
            can[a[i].second] = true;
            cnt++;
        }
    }
//    for (int i = 0; i + 1 < n; i++) {
//        if (pre[i] >= a[i + 1].first) {
//            can[a[i].second] = true;
//            cnt++;
//        }
//    }
    cout << cnt + 1 << endl;
    for (int i = 0; i < n; i++) {
        if (can[i]) cout << i + 1 << space;
    }
    cout << endl;


}

int main() {
//    freopen("in" , "r" , stdin);
//    freopen("out.txt" , "w" , stdout);
    IO;
    int q = 1;
    if (query) cin >> q;
    for (int i = 1; i <= q; i++) {
//        cout << "Case #" << i << ": ";
        solve();
    }
}