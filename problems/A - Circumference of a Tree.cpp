#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define EPS 0.000000001
#define space " "

const int maxN = 3 * 100000 + 4;
vector<vector<int>> g(maxN);
int node = 0;
int max_dep = 0;

void dfs(int cur = 0, int par = -1, int depth = 0) {
    if (max_dep < depth) {
        max_dep = depth;
        node = cur;
    }
    for (auto to : g[cur]) {
        if (to == par) continue;
        else {
            dfs(to , cur , depth + 1 ) ;
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u-- ; v-- ;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0) ;
    dfs(node) ;
    cout << max_dep * 3  << endl;

}