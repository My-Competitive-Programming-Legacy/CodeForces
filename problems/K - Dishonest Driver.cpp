#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endll "\n"
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll INF = 301;
const int N = 2005;
const int MOD = 1e9 + 7;
int n;
string s;
const int maxN = 702;
int dp[maxN][maxN];

bool can(int l, int r, int sz) {
    // int part = (r-l+1) /sz;
    for (int i = l + sz; i <= r; i++) {
        if (s[i] != s[i - sz])return false;
    }
    return true;
}

int solve(int l = 0, int r = n - 1) {
    if (l == r) {
        return 1;
    }
    if (dp[l][r] != -1) {
        return dp[l][r];
    }
    int ans = INT_MAX;
    int sz = (r - l + 1);
    for (int i = 1; i < sz; i++) {
        if (sz % i == 0)
            if (can(l, r, i)) {
                ans = min(ans, solve(l, l + i - 1));
            }
    }
    for (int i = l; i < r ; i++) {
        ans = min(ans, solve(l, i) + solve(i + 1, r));
    }
    return dp[l][r] = ans;

}

int main() {
    IO;
    for (int i = 0; i <= 700; i++) {
        for (int j = 0; j <= 700; j++) {
            dp[i][j] = -1;
        }
    }
    cin >> n;
    cin >> s;
    cout << solve(0, n - 1) << endl;
    return 0;
}