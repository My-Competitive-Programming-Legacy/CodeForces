#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> e, o;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t % 2) e.push_back(t);
        else o.push_back(t);
    }
    for (auto v : e) cout << v << " ";
    for (auto v : o) cout << v << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}