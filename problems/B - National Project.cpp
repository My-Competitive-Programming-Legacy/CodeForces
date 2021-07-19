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
using namespace std;

int main() {
    IO;
    int q;
    cin >> q;
    while (q--) {
        ll n , g, b ;
        cin >> n >> g >> b ;
        ll res =0 ;
        ll l = n , r = (ll)LLONG_MAX ;
        while(l <=r){
            ll mid = l  + (r - l ) / 2 ;
            ll good = ((mid/(g+b)) * g + min(g, mid%(g+b))) ;
            if(mid >=n &&  good  >= ceil(n/2.0)){
                res= mid ;
                r = mid -1 ;
            }else
                l = mid+ 1 ;

        }
        cout << res << endl ;

    }
    return 0;
}