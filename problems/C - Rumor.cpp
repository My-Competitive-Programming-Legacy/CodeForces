#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.000000001
#define pb push_back
#define space " "
#define ar array
#define pi pair<int,int>
#define ff first
#define ss second
const vector<int> dx = {-2, -2, 2, 2, 1, -1, 1, -1};
const vector<int> dy = {1, -1, 1, -1, -2, -2, 2, 2};
const int maxN = 100000;
int c[maxN + 1], vis[maxN + 1];
vector<int> g[maxN + 1];
int n, m;

ll dfs(int cur) {
    vis[cur] = true;
    ll res = c[cur];
    for (auto to : g[cur]) {
        if (!vis[to]) {
            res = min(res, dfs(to));
        }
    }
    return res;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            ans += dfs(i);
        }
    }
    cout << ans << endl;
}

int main() {
    int q = 1;
   // cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}