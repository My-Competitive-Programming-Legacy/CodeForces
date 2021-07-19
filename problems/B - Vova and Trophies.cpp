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

using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define PI atan(1)*4
const int maxN = 1000000;
const int N = maxN + 3;
int start[N];

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vi a;
    int raw = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'S') {
            if (raw != 0) a.push_back(raw);
            a.push_back(0);
            raw = 0;
        } else {
            raw++;
        }
    }
    if (raw != 0) a.push_back(raw);
    int sz = a.size();
    vi post(sz);
    for (int i = sz - 1; i >= 0; i--) {
        if (i == sz - 1) post[i] = a[i];
        else post[i] = a[i] + post[i + 1];
    }
    vi pre(sz);
    for (int i = 0; i < sz; i++) {
        if (i == 0) pre[i] = a[i];
        else pre[i] = a[i] + pre[i - 1];
    }
    int ans = 0;
    for (int i = 0; i < sz; i++) {
        if (a[i] == 0) {
            int can = 0;
            if (i + 1 < sz) can += a[i + 1];
            if (i - 1 >= 0) can += a[i - 1];
            bool before = ((i - 2) >= 0) && pre[i - 2] > 0;
            bool after = ((i + 2) < sz) && post[i + 2] > 0;
            if (before || after)
                ans = max(ans, can + 1);
            else
                ans = max(ans, can);
        } else {
            ans = max(ans, a[i]);
        }
    }
    cout << ans << endl;

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
    // cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}