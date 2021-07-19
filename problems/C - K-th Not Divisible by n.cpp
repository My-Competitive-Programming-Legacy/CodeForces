#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"
#include <set>
#include <map>

using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>

void solve() {
    int q;
    cin >> q;
    while (q--) {
       int n , k ;
       cin >> n >> k ;
       ll res = 0;
       ll l = 1 , r = LONG_LONG_MAX ;
       while(l <= r ) {
           ll mid = l + (r- l ) / 2 ;
           if(mid - (mid /n) == k ) {
               res = mid ;
               r = mid - 1 ;
           }else if((mid - mid /n) > k) {
               r = mid - 1 ;
           }else {
               l = mid + 1 ;
           }
       }
       cout << res << endl ;
    }
}
//cout << "Case #" << i << ": ";
    int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
#endif
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        solve();
        return 0;
    }