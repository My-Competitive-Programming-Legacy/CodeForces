#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

void solve() {
    string s;
    getline(cin, s);
    int n = stoi(s);
    getline(cin, s);
    int len = 0;
    vector<int> a;
    int sz = (int) s.size();
    int lb = -1;
    for (int i = 0; i < sz; i++) {
        len++;
        if (s[i] == ' ' || s[i] == '-') {
            a.push_back(len);
            lb = max(lb, len);
            len = 0;
        }
    }
    lb = max(lb , len ) ; 
    a.push_back(len);
//    for (int i = 0; i < (int) a.size(); i++) {
//        cerr << a[i] << " ";
//    }
    int ans = -1;
    int rb = sz;
    while (lb <= rb) {
        int mb = (lb + rb) / 2;
        int pre = 0;
        int lines = 0;
        for (int i = 0; i < (int) a.size(); i++) {
            if (pre + a[i] > mb) {
                lines++;
                pre = a[i];
            } else {
                pre += a[i];
            }
        }
        if (pre != 0)
            lines++;
        if (lines <= n) {
            ans = mb;
            rb = mb - 1;
        } else {
            lb = mb + 1;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO5
    int q = 1;
    // cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}