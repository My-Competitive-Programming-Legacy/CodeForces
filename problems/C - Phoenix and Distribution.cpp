#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <sstream>
#include <random>
#include <iterator>

typedef long long int ll;
using namespace std;
#define vl vector<ll>
#define vi vector<int>
#define space " "


void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    set<char> st;
    for (int i = 0; i < k; i++) st.insert(s[i]);
    if (k == 1) {
        cout << s << endl;
    } else if (st.size() > 1) {
        cout << *(st.rbegin()) << endl;
    } else {
        if(s[k] == s[n-1]) {
            int sz = n - 1 - k + 1 ;
            int par = ceil(sz / (double)k) ;
            string t = "" ;
            t += s[0] ;
            for(int i = 0 ; i < par ; i++ ) t += s[k] ;
            cout << t << endl ;

        }else {
            string t = s.substr(k - 1);
            cout << t << endl;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
//    solve();

    return 0;
}