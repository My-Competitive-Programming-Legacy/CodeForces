#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cstring>
#include <map>
#include <unordered_set>
#include <cmath>

#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef  long long int ll;
#define linebreak "\n"
#define space " "
#define E 10
#define MAX 1e9
#define MOD (int)(1000000007)
#define vi vector<int>
using namespace std;
int cnt(ll a ) {
    int res = 0 ;
    while(a != 0 ){
        res++ ;
        a/= 2 ;
    }
    return res  ;
}


ll solve(ll l, ll r) {
    if (l == 0 && r == 0)
        return 0;
    int maxbits = cnt(r);
    int minbits = cnt(l);
    if (maxbits > minbits) {
        ll res = -1;
        if (r == pow(2, maxbits) - 1) res = r;
        else
            res = pow(2, maxbits - 1) - 1;

        return res;
    }
    minbits -- ;
    ll biggest = (ll) pow(2, minbits);
    return biggest + solve(l - biggest, r - biggest);
}

/**Global stuff */


int main() {
//    cout << (ll)pow(2 , 60 ) -1 <<endl ;
//    cout << (ll)pow(2 , 59 ) -1 << endl ;
//    cout << (ll)pow(2 , 58 ) -1 << endl ;
//    cout << (ll)pow(2 , 57 ) -1 << endl ;
//    cout << (ll)1e18- 576460752303423487  << endl ;
//    cout << log2(1152921504606846975) + 1 << endl  ;
//    cout << cnt(1152921504606846975) ;
    IO;
    int q;
    cin >> q;
    while (q--) {
        ll l, r;
        cin >> l >> r;
//        cout << "Taken suucccsfdfajd;d" ;
//        cout << l <<  endl << r << endl ;
       cout << solve(l, r) << endl;
    }
    return 0;


}