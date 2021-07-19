#include <bits/stdc++.h>
/*
Created on 6/30/2021 by Hamza Hassan:
*/
using namespace std;
typedef long long int ll;
#define space " "
#define debug(val) "[ " << #val " : " << (val) << " ]" << space
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define PI (double)(atan(1)*4)

#define INF LONG_LONG_MAX
#define EPS (double)0.0000000001
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
const int Mod = (int) ((int) 1e9 + 7);

void solve() {
    long long int n, m, k, x, y;
    cin >> n >> m >> k >> x >> y;
    vector<vector<ll>> a(n, vector<ll>(m, 0));
    x -= 1;
    y -= 1;
    if (n == 1) {
        for (int i = 0; i < m; i++) {
            a[n - 1][i] += k / m;
            if (k % m > i) {
                a[n - 1][i] += 1;
            }
        }
        goto badcode;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (k) {
                a[i][j] += 1;
                k -= 1;
            }
        }
    }

    if (k == 0) {
        badcode:
        long long int mx = 0;
        long long int mn = LONG_LONG_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mx = max(mx, a[i][j]);
                mn = min(mn, a[i][j]);
            }
        }
        cout << mx << ' ' << mn << ' ' << a[x][y] << endl;
        return;
    }
    ll rounds = 0;
    if (n > 1)
        rounds = k / ((n - 1) * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == n - 1) {
                a[i][j] += (rounds ) / 2;
            } else if (i == 0) {
                a[i][j] += (rounds + 1 ) / 2;
            } else {
                a[i][j] += rounds;
            }
        }
    }
    k -= rounds * (n - 1) * m;
    if (rounds % 2 == 1) {
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (k) {
                    a[i][j] += 1;
                    k--;
                }
            }
        }
    } else {
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                if (k) {
                    a[i][j] += 1;
                    k--;
                }
            }
        }
    }
    assert(k == 0 ) ;
    long long int mx = 0;
    long long int mn = LONG_LONG_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mx = max(mx, a[i][j]);
            mn = min(mn, a[i][j]);
        }
    }
    cout << mx << ' ' << mn << ' ' << a[x][y] << endl;

}

int main() {
    bool debug = false;


#ifdef  _SHIT
    freopen("../in", "r", stdin);
    freopen("../out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q = 1;
//    cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}