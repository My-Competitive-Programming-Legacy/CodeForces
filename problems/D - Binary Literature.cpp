#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

void solve() {

    int n;
    cin >> n;
    vector<string> s(3);
    cin >> s[0] >> s[1] >> s[2];

    auto construct = [&](string &s, string &t, char common) {
        vector<vector<char>> idx1(n + 1), idx2(n + 1);

        int x = n;
        for (int i = 2 * n - 1; i >= 0; i--) {
            if ((s[i] == common) && x > 0) {
                x -= 1;
            } else {
                idx1[x].push_back(s[i]);
            }
        }
        x = n;
        for (int i = 2 * n - 1; i >= 0; i--) {
            if ((t[i] == common) && x > 0) {
                x -= 1;
            } else {
                idx2[x].push_back(t[i]);
            }
        }
        string ans;
        for (int i = 0; i <= n; i++) {
            reverse(idx1[i].begin(), idx1[i].end());
            reverse(idx2[i].begin(), idx2[i].end());
            for (auto c : idx1[i]) ans += c;
            for (auto c : idx2[i]) ans += c;
            if (i < n)
                ans += common;
        }
        assert(ans.size() <= 3 * n);
        return ans;

    };
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            int o1 = 0, z1 = 0, o2 = 0, z2 = 0;
            for (auto c : s[i]) {
                if (c == '1') o1 += 1;
                else z1 += 1;
            }
            for (auto c : s[j]) {
                if (c == '1') o2 += 1;
                else z2 += 1;
            }
            if (o1 >= n && o2 >= n) {
                //
                cout << construct(s[i], s[j], '1') << endl;
                return;
            } else if (z1 >= n && z2 >= n) {
                cout << construct(s[i], s[j], '0') << endl;
                return;
            }
        }
    }
}


int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}