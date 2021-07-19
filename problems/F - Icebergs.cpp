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
#define FINF 1000000000000
#define EPS (double)0.0000000001
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
const int Mod = (int) ((int) 1e9 + 7);
//#define _DEBUG

#define ar array

ll area(vector<ar<ll, 2>> &a) {
    ll ans = 0;
    int n = (int) a.size();
    a.push_back(a[0]);
    for (int i = 0; i < n; i++) {
        ans += (a[i][0] * a[i + 1][1] - a[i + 1][0] * a[i][1]);
    }
//    ans += a[n - 1][0] * a[0][1] - a[0][0] * a[n - 1][1];
//    ans += (a[i+1][])*()
//    cout << ans << endl;
    return abs(ans);
}

void solve() {
    int q;
    cin >> q;
    ll ans = 0;
    for (int i = 1; i <= q; i++) {
        int n;
        cin >> n;
        vector<ar<ll, 2>> a(n);
        for (int j = 0; j < n; j++) {
            int x, y;
            cin >> x >> y;
            a[j] = {x, y};
        }
        ans += area(a);
    }
    cout << ans / 2 << endl;
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
//     cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}