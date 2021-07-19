#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define vii vector<vector<int>>
#define ld long double
const int mxN = 3 * 100 * 1000 + 5;
vector<pair<int, int>> g[mxN];
int vis[mxN];

void solve() {
    int n, k, d;
    cin >> n >> k >> d;
    queue<int> q;
    for (int i = 0; i < k; i++) {
        int p;
        cin >> p;
        p--;
        if (!vis[p]) {
            vis[p] = 1;
            q.push(p);
        }
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }
    set<int> ans;
    vector<int> par(n);
    while ((int) q.size()) {
        int sz = q.size();
        while (sz--) {
            int cur;
            cur = q.front();
            q.pop();
            for (auto to : g[cur]) {
                if (vis[to.first]) {
                    if (to.first != par[cur])
                        ans.insert(to.second);
                } else {
                    par[to.first] = cur;
                    vis[to.first] = 1;
                    q.push(to.first);
                }
            }
        }
    }
    cout << (int) ans.size() << endl;
    for (auto edge : ans) {
        cout << edge << space;
    }
    cout << endl;

}

int query = 0;

int main() {
    IO;
    int q = 1;
    if (query) cin >> q;
    while (q--) {
        solve();
    }
}