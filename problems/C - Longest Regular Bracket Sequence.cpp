#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <time.h>

#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define pb push_back
#define MOD (int)(1e9  + 7)


void solve() {
    string s;
    cin >> s;
    int n = (int) s.size();
    int dp[n + 4];
    stack<pair<int, int> > st;
    for (int i = 0; i < n; i++) {
        int nxt = (s[i] == '(') ? 1 : -1;
        if (nxt == 1) {
            dp[i] = -1;
            st.push({nxt, i});
        } else {
            if (st.empty())
                dp[i] = -1;
            else {
                int begin = st.top().second;
                st.pop();
                dp[i] = begin;
            }
        }
    }
    int ans = 0, freq = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] == -1) continue;
        int k = i;
        while (k > -1 && dp[k] > -1) {
            dp[i] = dp[k];
            k = dp[i] - 1;
        }
        if (dp[i] != -1)
            ans = max(ans, i - dp[i] + 1);
    }
    if (ans == 0) cout << "0 1" << endl;
    else {
        for (int i = 0; i < n; i++)
            if (dp[i] > -1 && i - dp[i] + 1 == ans) freq++;
        cout << ans << space << freq << endl;
    }


}

int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    IO;
//    int q;
//    cin >> q;
//    for (int i = 1; i <= q; i++) {
//        cout << "Case #" << i << ": ";
//        solve();
//    }
    solve();

    return 0;
}