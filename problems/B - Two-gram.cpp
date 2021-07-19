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
    IO ;
    int n ;
    string s ;
    cin >> n >> s ;
    multiset<string> st;
    int maxi = 0 ;
    string res = "";
    for(int i = 0  ; i < n-1 ; i++) {
        string tt = "";
        tt+= s[i] ;
        tt+= s[i+1] ;
        //cout << tt << endl ;
        st.insert(tt) ;
        if(st.count(tt) > maxi) {
            maxi = st.count(tt) ;
            res = tt ;
        }
    }
        cout << res << endl ;

    return 0;
}
