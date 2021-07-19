#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define debug(val) "[ " << #val " : " << (val)
#define space " "
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define PI (double)(atan(1)*4)
#define pb push_back
#define pi pair<int , int >
#define ff first
#define ss second
#define INF 2000000000
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};

struct Graph {
    vii g;
    int n;
    vi low, in, vis, lvl;
    int timer = 1;
    int bridges = 0;

    Graph(int n) {
        this->n = n;
        g.resize(n);
        for (int i = 0; i < n; i++) {
            low.pb(INF);
            in.pb(0);
            vis.pb(0);
            lvl.pb(0);
        }
    }

    void add_edge(int u, int v) {
        g[u].pb(v);
    }

    void dfs(int cur, int par = -1, int level = 0) {
        //cerr << "going from par = " << par + 1 << "to cur = " << cur + 1 << endl;
        vis[cur] = 1;
        lvl[cur] = level;
        in[cur] = timer++;
        for (auto to  : g[cur]) {
            if (!vis[to]) {
                dfs(to, cur, level + 1);
            }
        }
        for (auto to : g[cur]) {
            if (to == par) continue;
            low[cur] = min(low[to], low[cur]);
            low[cur] = min(in[to], low[cur]);
        }
        if (par != -1) {
            if (low[cur] > in[par]) bridges++;

        }
    }

    void print_res() {
        for (int i = 0; i < n; i++) {
            for (auto to : g[i]) {
                if (in[to] > in[i]) {
                    if (lvl[to] - lvl[i] == 1) cout << i + 1 << space << to + 1 << endl;
                    else cout << to + 1 << space << i + 1 << endl;
                }
            }
        }
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    Graph g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g.add_edge(u, v);
        g.add_edge(v, u);
    }
    g.dfs(0);
    if (g.bridges > 0) {
        cout << 0 << endl;
    } else {
        g.print_res();
    }
}

//#define _DEBUG

int main() {
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int q = 1;
    //cin >> q;
    for (int i = 1; i <= q; i++) {
        solve();
    }
}