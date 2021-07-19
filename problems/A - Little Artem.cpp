#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <time.h>

using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define pb push_back
#define MOD (int)(1e9  + 7)

int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
   int q ;
   cin >> q ;
   while(q -- ) {
       int n , m ;
       cin >> n >> m ;
       for(int i = 0 ; i < n ; i++ ) {
           for(int j = 0 ; j < m ; j++ ) {
               if(i + j == 0  )cout << 'W' ;
               else cout << 'B' ;
           }
           cout << endl;
       }
   }
    return 0;
}