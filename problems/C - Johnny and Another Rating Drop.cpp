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
#define debug(val) "[ " << #val " : " << (val) << " ]\n"
#define space " "
#define vi vector<int>
#define PI atan(1)*4
#define pb push_back
#define pi pair<int , int >
#define ff first
#define ss second
void solve() {
   ll n ;
   cin >> n ;
   ll res =0;
   for(ll i=1;i<=(ll)1e18;i*=2) res += n/i ;
   cout << res << endl;
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