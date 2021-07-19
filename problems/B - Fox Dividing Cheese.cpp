#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

#define linebreak "\n"
#define E 10
#define MAX 200000+10
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define space " "
#define MOD (int)1e9
typedef long long int ll;
using namespace std;


vector<pair<int, int>> solve(int a) {
    vector<pair<int, int>> st;
    st.push_back(make_pair(a, 0)) ;
    queue<int> q1;
    set<int> visited;
    q1.push(a);
    visited.insert(a);
    int level = 0;
    while (q1.size() != 0) {
        int n = q1.size();
        level++;
        while (n--) {
            a = q1.front();
            q1.pop();
            vector<int> div = {2, 3, 5};
            for (auto i : div) {
                if (a % i == 0 && !visited.count(a / i)) {
                    visited.insert(a / i);
                    q1.push(a / i);
                    st.push_back(make_pair(a / i, level));
                }
            }
        }

    }
    return st;
}

int main() {
    IO;
    int a, b;
    cin >> a >> b;
    vector<pair<int, int>> st = solve(a);
    vector<pair<int, int>> nd = solve(b);
    int res = (int) 2e9;
    for (int i = 0; i < (int) st.size(); i++) {
        for (int j = 0; j < (int) nd.size(); j++) {
            if (st[i].first == nd[j].first) {
                res = min(res, st[i].second + nd[j].second);
            }
        }
    }
    if (res == (int) 2e9) res = -1;
    cout << res << endl;
    return 0;
}