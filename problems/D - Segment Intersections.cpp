#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"
#include "unordered_map"
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
typedef unsigned long long int ull;
typedef long double ld;
#define debug(val) "[ " << #val " : " << (val)
#define space " "
#define vi vector<int>
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define PI (double)(atan(1)*4)
#define pb push_back
#define pi pair<int , int >
#define ff first
#define ss second
#define INF 2000000000
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
void solve() {
    ll n, k;
    cin >> n >> k;
    pi p1, p2;
    cin >> p1.ff >> p1.ss;
    cin >> p2.ff >> p2.ss;
    if (p1.ff > p2.ff) swap(p1, p2);
    else if (p1.ff == p2.ff) {
        if (p1.ss <= p2.ss) swap(p1, p2);
    }
    int l1 = p1.ff, r1 = p1.ss, l2 = p2.ff, r2 = p2.ss;
    ll cost = 0, benefit = 0, one = 0;
    int intersection = min(r2, r1) - max(l2, l1);
    if (intersection >= 0) {
        benefit = intersection;
        k -= n * benefit;
        one = abs(r2 - r1) + abs(l2 - l1);
    } else {
        cost = l2-r1;
        one = r2 - l1;
    }
    set<ll> answers ;
    ll optimal = LONG_LONG_MAX ;
    if (k > 0) {
        ll ans = 0;
        for (int i = 0; (k > 0) && i < n; i++) {
            ans += cost;
            ans += min(k * 1ll, one);
            k -= min(k * 1ll, one);
            optimal = min(optimal , ans + 2 * k ) ;
        }
        if(k > 0 ) ans += 2 * k ;
        optimal = min(optimal , ans) ;
        cout << optimal<< endl;
    } else {
        cout << 0 << endl;
    }
}


int main() {
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int q = 1;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        solve();
    }
}


//       ababkamts
//    t-> bbk
//    u->aaa