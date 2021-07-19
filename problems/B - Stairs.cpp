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
int get_len(ll n) {
    ll lb = 0, rb = min(n, 1414213562LL);
    ll ans = 0;
    while (lb <= rb) {
        ll mb = (lb + rb) / 2;
        if (mb * (mb + 1) / 2 <= n) {
            ans = mb;
            lb = mb + 1;
        } else {
            rb = mb - 1;
        }
    }
    return ans;
}

void solve() {
    ll n;
    cin >> n;
    ll last = 1;
    ll ans = 0;
    while (last <= n) {
        n -= last;
        ans++;
        ll x = get_len(last);
        x++;
        if (x > 1414213562LL)
            break;
        last = last * 2 + x * x;
    }
    cout << ans << endl;

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
    cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}