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
    cin >> n ;
    vi a(n) ;
    for(int i=0;i<n;i++){
        cin >> a[i] ;
    }
    int res= -1;
    for(int i=1;i<n-1;i++){
        if(a[i] > a[i-1] && (a[i] > a[i+1])) {
            res = i+1 ;
        }
    }
    if(res == -1 ) cout << "NO" <<endl;
    else {
        cout << "YES" << endl;
        cout << res-1 << space << res <<space <<  res+1 << endl;
    }
    

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
     //   cout << "Case #" << i << ": ";
        solve();
    }
}