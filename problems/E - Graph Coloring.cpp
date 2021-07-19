#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"
#include <set>
#include <time.h>
#include <deque>
#include <iomanip>
#include <map>
#include <queue>

using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define PI atan(1)*4
const int maxN = 5000;
const int N = maxN + 4;
vi g[N];
int res[N];
int dp[N][N];
int col[N];
vector<vi > connected;
vector<pair<int, int>> nums;

bool bfs(int v) {
    col[v] = 0;
    vi list;
    queue<int> q;
    q.push(v);
    vi c = {1, 0};
    while (!q.empty()) {
        int cur = q.front();
        list.push_back(cur);
        q.pop();
        for (int i = 0; i < (int) g[cur].size(); i++) {
            int adj = g[cur][i];
            if (col[adj] != -1) {
                if (col[adj] == col[cur]) {
                    return false;
                }
            } else {
                col[adj] = col[cur] ^ 1;
                c[col[adj]]++;
                q.push(adj);
            }
        }
    }
    nums.push_back({c[0], c[1]});
    connected.push_back(list);
    return true;
}

//#define debugTheShit

void solve() {
    int n, m;
    cin >> n >> m;
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    for (int i = 0; i <= maxN; i++) {
        col[i] = -1;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        if (col[i] == -1) {
            if (!bfs(i)) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    dp[0][0] = 0;
    int connectedComp = (int) nums.size();
    for (int i = 0; i < connectedComp; i++) {
        for (int j = 0; j <= n2; j++) {
            if (i == 1 && j == 2) {
                int x = 0;
            }
            dp[i][j] = -1;
            if (i == 0) {
                if (j == nums[i].first) dp[i][j] = 0;
                else if (j == nums[i].second) dp[i][j] = 1;
            } else {
                if (j - nums[i].first > -1 && dp[i - 1][j - nums[i].first] != -1) {
                    dp[i][j] = 0;
                } else if (j - nums[i].second > -1 && dp[i - 1][j - nums[i].second] != -1)
                    dp[i][j] = 1;
            }
        }
    }
#ifdef debugTheShit
    cerr << "Connected Compontent " << endl;
    for (vi l : connected) {
        for (auto i : l) {
            cerr << i << space;
        }
        cerr << endl;
    }
    cerr << "Connected array" << endl;
    for (auto i : nums) {
        cerr << i.first << space;
    }
    cerr << endl;
    for (auto i : nums) {
        cerr << i.second << space;
    }
    cerr << endl;
    cerr << "Dp array " << endl;
    for (int i = 0; i <= n2; i++) {
        for (int j = 0; j < (int) connectedComp; j++) {
            cerr << dp[j][i] << space;
        }
        cerr << endl;
    }
#endif
    // build the 5ra
    if (dp[connectedComp - 1][n2] != -1) {
        cout << "YES" << endl;
        int j = n2;
        for (int i = connectedComp - 1; i >= 0; i--) {
            int val = dp[i][j];
            for (int cur : connected[i]) {
                if ((col[cur] == 1 && val == 1) || (col[cur] == 0 && val == 0))
                    res[cur] = 2;
            }
            if (val == 0 ) {
                j -= nums[i].first;
            } else if (val == 1  )
                j -= nums[i].second;
            else {
                cout << "Corrupted dp  " << endl;
            }
        }
        for (int i = 0; i < n; i++) {
            if (res[i] != 2) {
                if (n1 > 0) {
                    cout << 1;
                    n1--;
                } else
                    cout << 3;
            } else
                cout << res[i];
        }
    } else
        cout << "NO" << endl;
}

int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q = 1;
    //  cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}