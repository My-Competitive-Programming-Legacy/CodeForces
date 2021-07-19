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
const int maxN = 10000000;

void solve() {
    int n, m;
    cin >> n >> m;
    if (n == 1) cout << 0 << endl;
    else if (n > 2 ) cout << 2 * m << endl;
    else cout << m << endl;
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
        solve();
        //cout << "Case #" << i << ": ";
    }
}