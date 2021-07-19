#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define E 10
#define MAX 200000+10
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define space " "

int main() {
    int q ;
    cin >> q ;
    while(q--) {
        int n ;
        int a , b ,c ;
        bool ok = false ;
        cin >> n ;
        vector<int> fac ;
        for(int i = 2 ; (i * i) <=n ; i++) {
            if(n % i == 0 ) fac.push_back(i) ;
        }
        for(int i : fac ) {
            for(int j : fac) {
                if ( i!= j && n % (i*j) == 0) {
                    int third = n/(i*j) ;
                    if(i != third && j!= third ) {
                        ok = true ;
                        a = i ;
                        b = j ;
                        c = third ;
                        break ;
                    }
                }
            }
        }

        if(ok ) cout << "YES" << endl << a  << space << b << space << c << endl ;
        else cout << "NO" << endl ;

    }
    return 0;
}