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

typedef long long int ll;
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define linebreak "\n"
#define space " "
#define PI atan(1)*4
#define E 5
#define ACCURATE cout << fixed << setprecision(20)
#define MAX 1e9
#define MOD (int)(998244353 )
//#define _DEBUG
using namespace std;

int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IO;
    int n ;
    cin >> n ;
    set<ll> st ;
    for(int i = 0 ; i < n ;i++) {
        ll t ;
        cin >> t;
        st.insert(t) ;
    }
    vector<ll> ans ;
    for(set<ll>::iterator it = st.begin() ; it != st.end() ; it++) {
        ll cur = *it ;
        vector<ll > res ;
        res.push_back(*it) ;
        bool ok = true ;
        while(ok) {
            if(st.count(cur * 2)) {
                res.push_back(2*cur) ;
                cur *= 2 ;
            }else if(cur%3 == 0 && st.count( cur /3)) {
                res.push_back(cur/3) ;
                cur = cur / 3 ;
            }else ok =false ;

        }
        if(res.size() == n) {
            ans = res ;
            break ;
        }
    }
    for(int i = 0  ; i< n ; i++) cout << ans[i] << space ;

    return 0;
}
