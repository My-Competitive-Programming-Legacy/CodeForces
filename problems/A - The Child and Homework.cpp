#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define vii vector<vector<int>>
int query = 0;

void solve() {
    vector<int> a(4), can(4);
    int n = 4;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a[i] = s.size() - 2;
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
        ok = true ; 
        for (int j = 0; j < 4; j++) {
            if(i == j ) continue ;
            if (2 * a[i] <= a[j]) {

            } else {
                ok = false;
            }
        }
        if (ok) {
            can[i] = 1;
        }

        ok = true;
        for (int j = 0; j < 4; j++) {
            if(i == j ) continue ;

            if ( a[i] >= 2 *  a[j]) {

            } else {
                ok = false;
            }
        }
        if (ok) {
            can[i] = 1;
        }


    }
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        cnt += can[i];
    }
    if (cnt != 1) {
        cout << "C" << endl;
    } else {
        for(int i=0;i<4;i++){
            if(can[i]) {
                cout << (char)('A' + i) << endl;
                break;
            }
        }
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