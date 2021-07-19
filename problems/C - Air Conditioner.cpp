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
bool intersect(ll l1 , ll r1 , ll l2 , ll r2 ) {
    if(l1 <= l2 ) return r1 >= l2 ;
    else return intersect(l2  , r2 , l1 , r1 ) ;
}
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    IO;
    int q ;
//    cout<< intersect(1,2,2,3) << endl;
//    cout<< intersect(1,1,1,1) << endl;
//    cout<< intersect(1,2,3,4) << endl;
//    cout<< intersect(1,5,2,3) << endl;
//    cout<< intersect(2,3,1,5) << endl;
    cin >>q ;
    while(q--) {
        int n , m ;
        cin >> n >> m ;
        vector<ll> t ;
        vector<ll> l ;
        vector<ll> r ;
        for(int i = 0 ; i <n  ;i++) {
            int a , b ,c ;
            cin >> a >> b >> c ;
            t.push_back(a) ;
            l.push_back(b) ;
            r.push_back(c) ;
        }
        ll lr = m ;
        ll rr = m ;
        ll time = 0 ;
        bool ok = true;
        for(int i = 0 ; ok && i<n  ; i++) {
            if(intersect(lr-t[i] + time  , rr+t[i] - time , l[i] , r[i]))
            {
                lr = max(lr - t[i] + time, l[i]);
                rr = min(rr+ t[i] -time,r[i] );
                time = t[i] ;

            }else
                ok = false ;
        }
        if(ok ) cout << "YES" << endl; else cout << "NO" << endl;



    }
    return 0;
}