#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <time.h>

using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define pb push_back

#define MOD (int)(1e9  + 7)
vi g[2 * 100 * 1000 + 3];
int n, k;
//vi t(2 * 100 * 1000 + 3) ;
vi t(200000 + 3);

int dfs(int parent = -1, int cur = 0, int dep = 0, int h = 0) {
    t[cur] = dep;
    int braches = 0;
    for (int i = 0; i < (int) g[cur].size(); i++) {
        if (g[cur][i] != parent) {
           braches +=1 + dfs(cur, g[cur][i], dep + 1);
            //braches++;
        }
    }
    t[cur] -= braches;
    return braches;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs();
    sort(t.begin(), t.begin() + n, greater<>());
    ll res = 0;
    for (int i = 0; i < k; i++) {
        res += t[i];
    }
    cout << res << endl;
    return 0;

}