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

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vi a(n);
        vi dp[205];
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            a[i] = t;
            dp[t].push_back(i);
        }
        int ans = 1;
        for (int i = 1; i <= 200; i++) {
            ans = max(ans, (int) dp[i].size());
            for (int j = 1; j <= 200; j++) {
                if (i == j) continue;
                if (i == 1 && j == 2)
                    int x = 3;
                int res = 0;
                if (dp[i].size() == 0 || dp[j].size() == 0)continue;
                int l = 0;
                int r = (int) dp[i].size() - 1;
                while (l < r) {
                    res += 2;
                    int ms = lower_bound(dp[j].begin(), dp[j].end(), dp[i][l]) - dp[j].begin();
                    int me = upper_bound(dp[j].begin(), dp[j].end(), dp[i][r]) - dp[j].begin() - 1;
                    if (me != -1 && me < (int) dp[j].size() && ms < (int) dp[j].size()) {
                        ans = max(ans, res + me - ms + 1);
                    }
                    l++, r--;
                }
            }
        }
        cout << ans << endl;


    }
    return 0;

}