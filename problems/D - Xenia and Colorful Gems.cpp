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
#define vi vector<ll>
#define pb push_back

#define MOD (int)(1e9  + 7)

ll f(ll a, ll b) {
    return (b - a) * (b - a);
}

ll ans = LONG_LONG_MAX;

void solve(vi l, vi m, vi r) {
    int sl = (int) l.size();
    int sm = (int) m.size();
    int sr = (int) r.size();
    ll res = LONG_LONG_MAX;
    for (int i = 0; i < sm; i++) {
        int idxl = upper_bound(l.begin(), l.end(), m[i]) - l.begin() -1  ;
        int idxr = lower_bound(r.begin(), r.end(), m[i]) - r.begin();
        if (idxl != -1 &&  idxl < sl && idxr < sr) {
            res = min(res, f(m[i], l[idxl]) + f(m[i], r[idxr]) + f(l[idxl], r[idxr]));
        }
    }
    ans = min(ans, res);
}


int main() {
//    cout << LONG_LONG_MAX << endl;
    int q;
    cin >> q;
    while (q--) {
        ans = LONG_LONG_MAX;
        int nr, ng, nb;
        cin >> nr >> ng >> nb;
        vi a(nr);
        vi b(ng);
        vi c(nb);
        for (int i = 0; i < nr; i++) cin >> a[i];
        for (int i = 0; i < ng; i++) cin >> b[i];
        for (int i = 0; i < nb; i++) cin >> c[i];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        solve(a, b, c);
        solve(c, b, a);
        solve(a, c, b);
        solve(b, c, a);
        solve(b, a, c);
        solve(c, a, b);
        cout << ans << endl;

    }

    return 0;

}