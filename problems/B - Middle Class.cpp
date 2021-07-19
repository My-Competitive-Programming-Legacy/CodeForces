#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define pb push_back

int main() {
    int q ;
    cin >> q;
    while(q -- ) {
     int n , x ;
     cin >> n >> x ;
     vi a(n) ;
     for(int i =0 ; i < n ;i++ ){
         cin >> a[i] ;
     }
     sort(a.begin()  , a.end() , greater<>()) ;
     ll carry = 0 ;
     int ans = 0;
     for(int i = 0  ;i  < n ; i++ ){
         if(a[i] >= x ) {
             ans ++ ;
             carry +=a[i] - x ;
         }else {
             if(x - a[i] <= carry ) {
                 ans ++ ;
                 carry -= (x-a[i]);
             }
         }
     }
     cout << ans << endl;
    }

    return 0;

}