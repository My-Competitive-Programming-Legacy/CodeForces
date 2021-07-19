#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <sstream>
#include <random>
#include <iterator>

typedef long long int ll;
using namespace std;
#define vl vector<ll>
#define vi vector<int>
#define space " "


void solve() {
    ll x,y,a,b ;
    cin >> x >> y >> a >> b ;
    ll cost = a * x + a * y ;
    cost = min(cost , min(x,y)*b + a*(abs(x - y ))) ;
    cout <<cost << endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
//    solve();

    return 0;
}