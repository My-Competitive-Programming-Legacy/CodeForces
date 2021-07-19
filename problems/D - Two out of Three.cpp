#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define space " "
#define debug(val) "[ " << #val " : " << (val) << " ]" << space
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define PI (double)(atan(1)*4)
#define pb push_back
#define ff first
#define ss second
#define pi pair<int , int >
#define INF LONG_LONG_MAX
#define EPS (double)0.0000000001
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};

//#define _DEBUG
const int maxN = 1e3 + 10;
const int inf = 1e9;
const int Mod = 1e9 + 7;
int n;

vector<int> a(maxN);
int dp[maxN][maxN];

int solve(int have, int i) { // one based please :)
    if (i > n + 1) {
        cerr << "Error " << endl;
    }
    if (i > n)
        return dp[have][i] = a[have];
    else if (i == n) {
        return dp[have][i] = max(a[i], a[have]);
    }
    if (dp[have][i] != -1) {
        return dp[have][i];
    }
    int ans = inf;
    int ans1 = inf, ans2 = inf, ans3 = inf;
    if (have == 0) {
        if (i + 1 <= n)ans1 = max(a[i], a[i + 1]) + solve(0, i + 2);
        if (i + 2 <= n)ans2 = max(a[i + 1], a[i + 2]) + solve(i, i + 3);
        if (i + 2 <= n)ans3 = max(a[i], a[i + 2]) + solve(i + 1, i + 3);
        ans = min(ans1, min(ans2, ans3));
    } else {
        if (i + 1 <= n)ans1 = max(a[i], a[i + 1]) + solve(have, i + 2);
        if (i + 0 <= n)ans2 = max(a[have], a[i]) + solve(0, i + 1);
        if (i + 1 <= n)ans3 = max(a[have], a[i + 1]) + solve(i, i + 2);
        ans = min(ans1, min(ans2, ans3));
    }

    return dp[have][i] = ans;
}

void solve() {
    cin >> n;
    for (int i = 0; i <= 1002; i++) {
        for (int j = 0; j <= 1002; j++) {
            dp[i][j] = -1;
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << solve(0, 1) << endl;
    vector<pair<int, int>> ans;
    int have = 0, idx = 1;
    while (true) {
        if (idx == n) {
            pair<int, int> p = {n, -1};
            if (have != 0) p.ss = have;
            ans.push_back(p);
            break;
        } else if (have && idx > n) {
            ans.push_back({have, -1});
            break;
        } else if (!have && (idx > n)) {
            break;
        }
        if (have == 0) {
            //        if (i + 1 <= n)ans1 = max(a[i], a[i + 1]) + solve(0, i + 2);
            //        if (i + 2 <= n)ans2 = max(a[i + 1], a[i + 2]) + solve(i, i + 3);
            //        if (i + 2 <= n)ans3 = max(a[i], a[i + 2]) + solve(i + 1, i + 3);
            if (dp[have][idx] - max(a[idx], a[idx + 1]) == dp[0][idx + 2]) {
                ans.push_back({idx, idx + 1});
                have = 0, idx = idx + 2;
            } else if (dp[have][idx] - max(a[idx + 1], a[idx + 2]) == dp[idx][idx + 3]) {
                ans.push_back({idx + 1, idx + 2});
                have = idx;
                idx = idx + 3;
            } else if (dp[have][idx] - max(a[idx], a[idx + 2]) == dp[idx + 1][idx + 3]) {
                ans.push_back({idx, idx + 2});
                have = idx + 1;
                idx = idx + 3;
            } else {
                cerr << "Error, fuck you " << endl;
            }
        } else {
//            if (i + 1 <= n)ans1 = max(a[i], a[i + 1]) + solve(have, i + 2);
//            if (i + 0 <= n)ans2 = max(a[have], a[i]) + solve(0, i + 1);
//            if (i + 1 <= n)ans3 = max(a[have], a[i + 1]) + solve(i, i + 2);
            if (dp[have][idx] - max(a[have], a[idx]) == dp[0][idx + 1]) {
                ans.push_back({have, idx});
                have = 0, idx += 1;
            } else if (dp[have][idx] - max(a[idx], a[idx + 1]) == dp[have][idx + 2]) {
                ans.push_back({idx, idx + 1});
                have = have, idx += 2;
            } else if (dp[have][idx] - max(a[have], a[idx + 1]) == dp[idx][idx + 2]) {
                ans.push_back({have, idx + 1});
                have = idx, idx += 2;
            } else {
                cerr << "Fuck you this an error " << endl;
            }
        }
    }

    for (auto p : ans) {
        cout << p.ff << space;
        if (p.ss != -1) cout << p.ss;
        cout << endl;
    }

}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int q = 1;
    // cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }

}