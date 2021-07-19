#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cstring>
#include <map>
#include <unordered_set>
#include <cmath>
#include <iomanip>

#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int ll;
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define f first
#define s second
#define linebreak "\n"
#define space " "
#define PI atan(1)*4
#define E 10
#define ACCURATE cout << fixed << setprecision(20)
#define MAX 1e9
#define MOD (int)(1000000007)
#define vi vector<int>
#define N (int)(1e7)
#define _DEBUG
using namespace std;

int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    IO;
    int q ;
    cin >> q ;
    while(q-- ) {
      int n ;
      cin >> n ;
      vector<int> a ;
      for(int i = 0 ; i< n ; i++)  {
          int t;
          cin >> t ;
          a.push_back(t) ;
      }
      int maxTarget = -1 ;
      int minTarget  = (int)2e9;
      int delta = 0 ;
      for(int i = 0 ; i < n ; i++) {
          if(a[i] == -1 ) {
              if(i > 0)
              {
                  if(a[i-1] != -1) minTarget = min(minTarget , a[i-1]) ;
                  if(a[i-1] != -1)  maxTarget = max(maxTarget , a[i-1]) ;
              }
              if(i < n-1)
              {
                  if(a[i+1] != -1) minTarget = min(minTarget , a[i+1]) ;
                  if(a[i+1] != -1) maxTarget = max(maxTarget , a[i+1]) ;
              }

          }
          if(i<n-1 && a[i+1] != -1 && a[i] != -1 ){
              delta = max(delta , abs(a[i] - a[i+1]) ) ;
          }
      }
      if(minTarget == 2e9 && maxTarget == -1){
          cout << 0 << space << 1 << endl;
      }else {

          int k = (maxTarget - minTarget) / 2 + minTarget;
           delta = max(delta , max(abs(k - maxTarget), abs(minTarget - k)) ) ;

          cout <<  delta << space << (maxTarget - minTarget) / 2 + minTarget
               << endl;
      }
    }
    return 0;
}