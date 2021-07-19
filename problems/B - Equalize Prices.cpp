#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define E 10
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q;
    cin >> q ;
    while (q--) {
        int min[120];
        int n , k ;
        cin >> n >> k ;
        int res = (int) 1e9 ;
        for(int i = 0 ; i < n ; i++) {
            int a ;
            cin >> a ;
            res = std::min(res , a+ k) ;
            min[i] = std::max(0 , a-k ) ;
        }
        bool ok = true ;
        for(int i = 0 ; i < n ; i++){
            if( res < min[i]) ok = false ;
        }
        if(ok ) cout << res << endl ;
        else cout << -1 << endl ;

    }


    return 0;
}