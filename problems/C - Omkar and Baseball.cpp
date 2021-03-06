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
#define debug(val) "[ " << #val " : " << (val)
#define space " "
#define vi vector<int>
#define PI (double)(atan(1)*4)
#define pb push_back
#define pi pair<int , int >
#define ff first
#define ss second
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};

void solve() {
    int n;
    cin >> n;
    bool in = false, out = false;
    int cnt = 0;
    vi a(n + 1);
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        if (t == i) {
            in = true;
            cnt++;
        } else {
            out = true;
        }
        a[i] = t;
    }
    if (in && out) {
        int i = 1;
        while (a[i] == i) {
            i++;
            cnt--;
        }
        i = n;
        while (a[i] == i) {
            i--;
            cnt--;
        }
        if (cnt == 0) {
            cout << 1 << endl;
        } else
            cout << 2 << endl;
    } else if (in && !out) cout << 0 << endl;
    else cout << 1 << endl;

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