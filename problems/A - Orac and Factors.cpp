#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"
#include <set>
#include <time.h>
#include <deque>
#include <iomanip>
#include <map>

using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
const double eps = 0.0000001;

void solve() {
  int n , k ;
  cin >> n>>k ;
  for(int i=2;i<=n;i++ ){
      if(n%i == 0 ) {n+=i;k--;break;}
  }
  cout << n + k * 2 << endl;

}


int main() {
#ifdef _DEBUG // place in cmake-build-debug folder 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
    int q = 1;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        solve();
        //cout << "Case #" << i << ": ";
    }
}