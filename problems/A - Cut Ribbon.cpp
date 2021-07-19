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
const int Mod = (int) ((int) 1e9 + 7);

//#define _DEBUG
void solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    /*
     * dp[i] -> dp[i+{a,b,c}] + dp[i]
     * dp[n]
     */
    vector<int> dp(n * 3, -1);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] != -1) {
            if (i + a <= n)dp[i + a] = max(dp[i + a], dp[i] + 1);
            if (i + b <= n)dp[i + b] = max(dp[i + b], dp[i] + 1);
            if (i + c <= n)dp[i + c] = max(dp[i + c], dp[i] + 1);
        }
    }
    cout << dp[n] << endl;


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
    //cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }

}