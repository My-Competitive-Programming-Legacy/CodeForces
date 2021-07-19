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
    int n, k;
    cin >> n >> k;
    vi a(n), b(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<>());
    bool ok = true;
    int i =0  ;
    while (k && ok && i <n  ) {
        if(a[i] < b[i] ) {
            sum -= a[i] ;
            sum += b[i] ;
            i++ ;
            k--;
        }else ok =false ;
    }
    cout << sum << endl;

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