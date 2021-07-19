#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define vii vector<vector<int>>
int query = 0;

void solve() {
    int n, k;
    cin >> n >> k;
    set<int> st ;
    for(int i=1;i<=n;i++){
        st.insert(i);
    }
    int a, b ,c ,d ;
    cin >> a >> b >> c >> d;
    st.erase(a) ;
    st.erase(b) ;
    st.erase(c) ;
    st.erase(d) ;
    if (n == 4 || k < n + 1) {
        cout << -1 << endl;
    } else {
        cout << a <<  space << c << space ;
        for(auto v : st) cout << v << space ;
        cout << d << space << b <<endl;

        cout << c << space << a << space ;
        for(auto v : st) cout << v << space ;
        cout << b << space << d << endl;

    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int q = 1;
    if (query == 1)
        cin >> q;
    for (int i = 1; i <= q; i++) {
        solve();
    }
}