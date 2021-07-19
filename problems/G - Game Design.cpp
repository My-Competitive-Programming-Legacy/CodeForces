#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endll "\n"
#define ar array
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll INF = 2e18;
const int mxN = 1e5, mxM = 6e2 + 1, MOD = 1e9 + 7;
vector<vector<int>> vec;
vector<int> dsu;
vector<int> tim;

bool can(string &s) {
    int n = (int) s.size();
    if(n<3)return true;
    string sub = s.substr(n - 3);
    vector<string> bad = {"RLR", "LRL", "UDU", "DUD"};
    for (int i = 0; i < 4; i++) {
        bool ok = true;
        for (int j = 0; j < 4; j++) {
            ok &= (sub[j] == bad[i][j]);
        }
        if (ok) {
            return false;
        }
    }

    return true;
}

int main() {
    IO;
    string str;
    cin >> str;
    if (!can(str)) {
        cout << "impossible" << endl;
        return 0;
    }
    int x, y;
    x = 0, y = 0;
    int cur = 0;
    vector<pair<int, int >> ans;
    vector<pair<int, int >> temp_ans;
    int n = str.size();
    for (int i = 0; i < n; i++) {
        int add = 1 << cur;
        cur++;
        if (str[i] == 'D') {
            if (ans.size() >= 2 && str[i - 1] == 'U' && str[i - 2] == 'D') {
                cur--;
                int k = temp_ans.size();
                x = temp_ans[k - 2].first;
                y = temp_ans[k - 2].second + 1;
                temp_ans.push_back({x, y - 1});
                continue;
            }
            y -= add;
            ans.push_back({x, y - 1});
            temp_ans.push_back({x, y - 1});
        } else if (str[i] == 'U') {
            if (ans.size() >= 2 && str[i - 1] == 'D' && str[i - 2] == 'U') {
                cur--;
                int k = temp_ans.size();
                x = temp_ans[k - 2].first;
                y = temp_ans[k - 2].second - 1;
                temp_ans.push_back({x, y + 1});
                continue;
            }
            y += add;
            ans.push_back({x, y + 1});
            temp_ans.push_back({x, y + 1});
        } else if (str[i] == 'L') {
            if (ans.size() >= 2 && str[i - 1] == 'R' && str[i - 2] == 'L') {
                cur--;
                int k = temp_ans.size();
                x = temp_ans[k - 2].first + 1;
                y = temp_ans[k - 2].second;
                temp_ans.push_back({x - 1, y});
                continue;
            }
            x -= add;
            ans.push_back({x - 1, y});
            temp_ans.push_back({x - 1, y});
        } else {
            if (ans.size() >= 2 && str[i - 1] == 'L' && str[i - 2] == 'R') {
                cur--;
                int k = temp_ans.size();
                x = temp_ans[k - 2].first - 1;
                y = temp_ans[k - 2].second;
                temp_ans.push_back({x + 1, y});
                continue;
            }
            x += add;
            ans.push_back({x + 1, y});
            temp_ans.push_back({x + 1, y});
        }
    }
    cout << -1 * x << " " << -1 * y << endl;
    cout << ans.size() << endl;
    for (pair<int, int> p : ans) {
        cout << p.first + (-1 * x) << " " << p.second + (-1 * y) << endl;
    }
    return 0;
}