#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"

using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>

const int maxN = 25821;
vector<ll> f(maxN);

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    while (n > 0) {
        int upper = upper_bound(f.begin(), f.end(), n) - f.begin();
        upper--;
        if(upper == 0 ) break ;
        n -= f[upper];
        ans++;
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
    f[0] = 0;
    for (int i = 1; i < maxN; i++) {
        f[i] = f[i - 1] + 2 + 3 * (i - 1);
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        //cout << "Case #" << i << ": ";

        solve();
    }

    return 0;
}