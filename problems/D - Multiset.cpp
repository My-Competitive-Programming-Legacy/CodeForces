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
const double eps = 0.0000001;

const int maxN = 1000000;
int fen[maxN + 3];

void build() {
    for (int i = 0; i <= maxN; i++) fen[i] = 0;
}

int sum(int r) {
    int res = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) res += fen[r];
    return res;
}

int range_sum(int l, int r) {
    if (l == 0) return sum(r);
    else return sum(r) - sum(l - 1);
}

void update(int idx, int delta) {
    for (; idx <= maxN; idx = (idx | (idx + 1))) {
        fen[idx] += delta;
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    build();
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        update(t, 1);
    }
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t > 0) {
            update(t, 1);
            continue;
        }
        t = -1 * t;
        int l = 0, r = maxN;
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int kth = sum(mid);
            if (kth >= t) {
                r = mid - 1;
                ans = mid;
            } else if (kth < t) {
                l = mid + 1;
            }
        }
        //  cerr << "delete the " <<ans << endl;
        update(ans, -1);
    }
    bool ok = false;
    for (int i = 0; i <= maxN; i++) {
        if (sum(i) != 0) {
            ok = true;
            cout << i << endl;
            break;
        }
    }
    if (!ok) cout << 0 << endl;
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
    //  cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}