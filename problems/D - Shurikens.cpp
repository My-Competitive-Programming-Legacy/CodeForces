#include <bits/stdc++.h>

using namespace std;
#define space " "
using ll =  long long int;

void solve() {
    int n;
    cin >> n;
    vector<int> ans(n);
    set<int> st;
    for (int i = 0; i < n; i++)st.insert(i);
    vector<pair<char, int >> input(2*n);
    stack<int> stk;
    for (int i = 0; i < 2 * n; i++) {
        //cerr << i <<endl;
        string t;
        cin >> t;
        input[i].first = t[0];
        int val;
        if (t[0] == '-') {
            cin >> val;
            input[i].second = val;
            if (stk.empty()) {
                cout << "NO" << endl;
                return;
            } else {
                int idx = stk.top();
                stk.pop();
                ans[idx] = val;
            }
        } else {
            stk.push(*st.begin());
            st.erase(st.begin());
        }
    }
   // cerr << "here" <<endl;
    bool ok = true;
    set<int> input_validator;
    int ptr = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (input[i].first == '+') {
            input_validator.insert(ans[ptr++]);
        } else {
            int to_remove = input[i].second;
            if (to_remove != *input_validator.begin()) {
                ok = false;
                break;
            } else {
                input_validator.erase(input_validator.begin());
            }
        }
    }
  //  cerr << "Here" <<endl;
    if (ok) {
        cout << "YES" << endl;
        for (auto v : ans) {
            cout << v << space;
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }


}

#define LOCAL

int main() {
//    freopen("gift1.in", "r", stdin);
//    freopen("gift1.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int q = 1;
//    cin >> q;
    while (q--) {
        solve();
    }
}