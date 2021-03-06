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
typedef long double ld;
#define debug(val) "[ " << #val " : " << (val)
#define space " "
#define vi vector<int>
#define PI (double)(atan(1)*4)
#define pb push_back
#define pi pair<int , int >
#define ff first
#define ss second
#define INF 2000000000
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
int get(int i , int j ) {
    cout << "? " << i << space << j << endl ;
    int f ;
    cin >> f ;
    return f;
}
void solve() {
    vi a = {16,8,4,15,23,42};
    vi n(4) ;
    for(int i=0;i<4;i++){
        n[i] = get(1,i+2)  ;
    }
    vi ans ;
    for(auto first : a ) {
       bool ok = true ;
       for(auto v : n ) {
           ok &= (v%first == 0 ) ;
       }
       if(ok) {
           ans.pb(first) ;
           for(auto v : n ) ans.pb(v/first) ;
           break;
       }
    }
    for(int  num : a ) {
        bool found = false ;
        for(int v : ans) if(v== num ) found = true ;
        if(!found) {
            ans.pb(num) ;
        }
    }
    cout << "! " ;
    for(int i=0;i<6;i++){cout << ans[i] << space ; }
    cout << endl;

}

//#define _DEBUG

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