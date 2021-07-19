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
#include <unordered_map>

typedef long long int ll;
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define linebreak "\n"
#define space " "
#define PI atan(1)*4
#define E 5
#define ACCURATE cout << fixed << setprecision(12)
#define MAX 1e9
#define MOD (int)(1e9 + 7 )
#define ExpMod (int)(1e9 + 6 )
//#define _DEBUG
using namespace std;
//#define _DEBUG
ll dp[1000005];

int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IO;
    int n , m  , p ;
    cin >> n >> m >> p  ;
    vector<ll> a(n) ;
    vector<ll> b(m) ;
    int ex1 , ex2 ;
    for(int i = 0 ; i < n ;i++) {
        cin >> a[i] ;
        if(a[i] % p != 0 ) ex1 = i ;
    }
    for(int j = 0 ; j < m ; j++) {
        cin >> b[j];
        if(b[j] % p != 0 ) ex2 = j ;
    }
    cout << ex1 + ex2 << endl ;


    return 0;
}