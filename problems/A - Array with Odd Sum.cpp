#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int ll;
#define linebreak "\n"
#define space " "
#define E 10
#define MAX 2e9+10
#define MOD (int)1e9
using namespace std;
int main() {
    IO;
    int q;
    cin >> q ;
    while(q-- ) {
        int n  ;
        cin >> n ;
        int o = 0 , e = 0 , sum = 0 ;
        for(int i = 0 ; i < n ;i++) {
            int  t ;
            cin >> t ;
            sum += t ;
            if(t%2 ) o++ ; else e++ ;
        }
        bool ok = true ;
        if(o == 0 ) {
            ok = false ;
        }else if(e == 0 ) {
            ok = n%2;
        }
        if(ok ) cout << "YES" <<endl ; else cout << "NO" <<endl ;

    }
}