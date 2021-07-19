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
#include <stack>
#include <memory.h>

using namespace std;
typedef long long int ll;
#define debug(val) "[ " << #val " : " << (val) << " ]\n"
#define space " "
#define vi vector<int>
#define PI atan(1)*4
#define pb push_back
#define pi pair<int , int >
const ll INF = LONG_LONG_MAX;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), w;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll res = 0;
    int l2 = 0;
    for (int i = 0; i < k; i++) {
        int t;
        cin >> t;
        w.push_back(t);
        if (t == 1) {
            res += 2 * a.back();
            a.pop_back();
            w.pop_back();
        } else
            l2 += t - 1;

    }
    sort(w.begin(), w.end(), greater<>());;
    int l = 0;
    for (int i = 0; i < (int)w.size(); i++) {
        res += a[l] ;
        l+= w[i]-1;
        res += a[l2++] ;
    }

    cout << res << endl;

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
        // cout << "Case #" << i << ": ";
        solve();
    }
}