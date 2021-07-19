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

using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define PI atan(1)*4
#define pb push_back
#define ff first
#define ss second
void solve() {
  int n ;
  cin >> n ;
  vi a(n) ;
  int o = 0 , e= 0;
  for(int i=0;i<n;i++){
      cin >> a[i] ;
      if(a[i] % 2 != i%2) {
          if(i%2) e++ ;
          else o++ ;
      }
  }
  if(e == o ) cout << e << endl;
  else cout << -1 << endl;
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