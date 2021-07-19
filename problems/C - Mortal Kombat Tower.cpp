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
#define mp make_pair
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
const int Mod = (int) ((int) 1e9 + 7);
#define ar array

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    const int inf = 1e6;
    vector<ar<int, 2>> dp(n + 5, {inf, inf});
    dp[0][1] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            if (j == 0) {
                dp[i + 1][1] = min(dp[i + 1][1], dp[i][j]);
                dp[i + 2][1] = min(dp[i + 2][1], dp[i][j]);
            } else {
                int c1 = a[i] == 1;
                dp[i + 1][0] = min(dp[i + 1][0], dp[i][j] + c1);
                if (i + 1 < n) {
                    int c2 = a[i + 1] == 1;
                    dp[i + 2][0] = min(dp[i + 2][0], dp[i][j] + c1 + c2);
                }
            }
        }
    }
    int ans = min(dp[n][1], dp[n][0]);
    cout << ans << endl;

}

int main() {
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO5
    int q = 1;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}