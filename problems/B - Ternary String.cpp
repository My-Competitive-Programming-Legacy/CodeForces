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
#define print(val) "[ " << #val " : " << (val) << " ]\n"
#define ff first
#define ss second

void solve() {
    string s;
    cin >> s;
    int n = (int) s.size();
    int ans = INT_MAX;
    vi a = {1};
    vi val = {s[0] - '0'};
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            a.back()++ ;
         
        } else {
            a.push_back(1);
            val.push_back(s[i] - '0');
        }

    }
    for (int i = 0; i < (int) a.size() - 2; i++) {
        if (val[i] != val[i + 1] && val[i + 1] != val[i + 2] && val[i] != val[i + 2])
            ans = min(ans, 2 + a[i + 1]);
    }
    if (ans == INT_MAX) ans = 0;
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
    cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}