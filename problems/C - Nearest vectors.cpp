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
typedef long double ld;
#define debug(val) "[ " << #val " : " << (val) << " ]\n"
#define space " "
#define vi vector<int>
#define PI (double)(atan(1)*4)
#define pb push_back
#define pi pair<int , int >
#define ff first
#define ss second

void solve() {
    int n;
    cin >> n;
    vector<pair<ld, int >> a;
    for (int i = 0; i < n; i++) {
        ld x, y;
        cin >> x >> y;
        ld angle = atan(abs(y / x)) * 180 / PI;
        //cerr << angle << endl;

        if (x < 0 && y >= 0) {
            angle = 180 - angle;
        } else if (x >= 0 && y < 0) {
            angle = 360 - angle;
        } else if (x < 0 && y < 0) {
            angle += 180;
        }
        a.pb({angle, i + 1});
    }
    sort(a.begin(), a.end());
    ld least = 400;
    pair<int, int> indices;
    for (int i = 1; i < n; i++) {
        if (a[i].first - a[i - 1].first < least) {
            indices = {a[i].ss, a[i - 1].ss};
            least = a[i].first - a[i - 1].first;
        }
    }
    if (a[0].ff + 360 - a[n - 1].ff < least) {
        least = a[0].ff + 360 - a[n - 1].ss;
        indices = {a[0].ss, a[n-1].ss};
    }
    cout << indices.ff << space << indices.ss << endl;

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
    //cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}