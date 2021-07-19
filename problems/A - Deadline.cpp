#include <iostream>
#include<bits/stdc++.h>
typedef long long int ll ;

using namespace std;
#define E 10
#define MAX 200000+10
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define space " "

int main() {
    int q ;
    cin >> q ;
    while(q--) {
      int n , d ;
      cin >> n >> d ;
      bool ok = false ;
      if(d<=n) {
          cout <<"YES" << endl ;
      }else {
          int l = 1 , r = n;
          while(l<=r){
              int mid1 = l + (r - l) / 3;
              int mid2 = r - (r - l) / 3;
              if(mid1 +ceil(d / (double)(mid1+1)) <= n){
                  ok = true ;
                  break ;
              }else if(mid2 +ceil(d / (double)(mid2+1)) <= n){
                  ok = true ;
                  break ;
              }else {
                  l = mid1 + 1;
                  r = mid2 - 1;
              }

          }
          if(!ok ) cout << "NO" << endl ;
          else cout << "YES" << endl ;

      }

    }


    return 0;
}