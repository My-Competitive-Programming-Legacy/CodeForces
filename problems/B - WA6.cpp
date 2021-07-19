#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endll "\n"
#define ar array
#define speed() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll INF = 1e18 + 18;
const int mxN = 2e5 + 5, MOD = 1e9 + 7;

int cal(int a, int b,int mod) {

    if (b == 0) return 1;
    if (b&1) {
        return a*cal(a,b-1,mod)%mod;
    } else {
        int x = cal(a,b/2,mod);
        return x*x%mod;
    }

}

void solve() {
    int n,m;
    cin >> n >> m;
    cout << cal(n,m-2,m);
}

int main() {
    speed()
    int t = 1; //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}