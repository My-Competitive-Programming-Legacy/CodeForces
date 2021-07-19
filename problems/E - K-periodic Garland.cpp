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
const double eps = 0.0000001;
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vi pre(n);
    vi post(n);
    vi dp(n);
    for (int i = 0; i < n; i++) {
        int cur = s[i] - '0';
        if (i != 0) pre[i] += cur + pre[i - 1];
        else pre[i] = cur;
    }
    for (int i = n - 1; i >= 0; i--) {
        int cur = s[i] - '0';
        if (i != n - 1) post[i] += cur + post[i + 1];
        else post[i] = cur ;
    }
    dp[0] = s[0] == '1' ? 0 : 1 ;
    for (int i = 1; i < n; i++) {
        int cost = 1;
        cost -= (s[i] - '0');
        dp[i] = INT_MAX;
        if (i - k >= 0) {
            int c1 = (dp[i - k]);
            c1 += pre[i - 1] - pre[i - k];
            dp[i] = min(dp[i], c1 + cost);
        }
        dp[i] = min(dp[i], pre[i - 1] + cost);
    }
    ll ans = dp[n - 1];
    for (int i = 0; i < n - 1; i++) {
        ans = min(ans, (ll) (dp[i] + post[i + 1]));
    }
    cout << min(ans, (ll) pre[n - 1]) << endl;

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
    cin >> q;
    for (int i = 1; i <= q; i++) {
        solve();
        //cout << "Case #" << i << ": ";
    }
}