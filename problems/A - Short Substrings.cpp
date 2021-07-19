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
  string s ;
  cin >> s ;
  string t = "" ;
  for(int i=0 ; i <(int)s.size() ; i+=2) t+= s[i] ;
  t += s[(int)s.size() -1 ] ;
  cout << t << endl;
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