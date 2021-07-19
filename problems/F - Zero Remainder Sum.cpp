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
#define INF (int)3e5
#define EPS (double)0.0000000001
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
const int Mod = (int) ((int) 1e9 + 7);
//#define _DEBUG

template<typename T>
// remove all occurrences of item in the container v
inline void remove(vector<T> &v, const T &item) {
    v.erase(std::remove(v.begin(), v.end(), item), v.end());
}

const bool debug = 0;
const int maxA = 70 * 35;
const int inf = (int) 1e9;

vector<int> fill(vector<int> &a, int k) {
    vector<int> ans(k, -inf);
    int n = (int) a.size();
    vector<vector<int>> dp(n, vector<int>(maxA + 3, inf));
    dp[0][0] = 0;
    dp[0][a[0]] = 1;
    int sum = 0;
    for (int i = 1; i < n; i++) {
        sum += a[i];
        for (int j = 0; j <= maxA; j++) {
            dp[i][j] = dp[i - 1][j];
            if ((j - a[i] >= 0)) {
                dp[i][j] = min(dp[i][j], 1 + dp[i - 1][j - a[i]]);
            }
            if (dp[i][j] <= n / 2) {
                ans[j % k] = max(ans[j % k], j);
            }
        }
    }
    if (debug) {
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j <= sum; j++) {
//                cerr << (dp[i][j] == inf ? -1 : dp[i][j]) << space;
//            }
//            cerr << endl;
//        }
//        cerr << endl;
        for (auto v : ans) cerr << v << space;
        cerr << endl;
    }
    return ans;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vii a(n, vi(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vii best(n, vi(k));
    for (int i = 0; i < n; i++) {
        best[i] = fill(a[i], k);
    }
    vii dp(n, vi(k, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            int res = best[i][j];
            if (i) {
                for (int l = 0; l < k; l++) {
                    int need = (j - l + k) % k;
                   // if (dp[i - 1][l] != 0 && best[i][need] != 0)
                        res = max(res, dp[i - 1][l] + best[i][need]);
                }
            }
            dp[i][j] = res;
        }
    }

    cout << max( 0 , dp[n - 1][0]) << endl;

}

int main() {
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int q = 1;
    //  cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}