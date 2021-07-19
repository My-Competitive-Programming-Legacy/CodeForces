#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define space " "
#define debug(val) "[ " << #val " : " << (val) << " ]" << space


void solve() {
    int n;
    cin >> n;
    auto win = [&](int x) {
//        cerr << x <<endl;
        if (0 < x && x < n) return false;
        else return true ;
//        if (n <= x && x <= n * (n - 1)) return true;
//        if (x > n * (n - 1) && x < n * n) return false;
    };
    bool ok = false;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        int tt = (t % (n * (n - 1))) ;
        if (win(tt)) {
            ok = true;
        }
    }
    if (ok) cout << "Alice" << endl;
    else cout << "Bob" << endl;

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
        //  cout << "Case #" << i << ": ";
        solve();
    }
}