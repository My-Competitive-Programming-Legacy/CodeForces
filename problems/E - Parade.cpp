#include <bits/stdc++.h>

#include <random>
#include <chrono>

using namespace std;
using ll = long long;
#define ar array
#define space " "
#define pb push_back
#define vi vector<int>
#define vii vector<vector<int>>
const double inf = 2e18;
#define EPS  0.0000000001
mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

const int START = 0;
const int END = 1;

struct Rect {
    int l, r;
    int h;
};

struct Event {
    int x, h;
    bool type;

    bool operator<(Event &o) const {
        /// start is damn first
        // if they are same then take the fucking
        if (x != o.x) {
            return x < o.x;
        } else if (o.type != type) {
            return type < o.type;
        } else {
            if (type == START)
                return h > o.h;
            else
                return o.h > h;
            
        }
    }

};

void solve() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<Rect> a(n);
    for (int i = 0; i < n; i++) {
        int l, r, h;
        cin >> h >> l >> r;
        a[i] = {l, r, h};
    }
    vector<Event> events;
    for (int i = 0; i < n; i++) {
        events.push_back({a[i].l, a[i].h, START});
        events.push_back({a[i].r, a[i].h, END});
    }
    vector<pair<int, int>> ans;
    sort(events.begin(), events.end());

    set<pair<int, int> > heights; // the second in the pair in the idx to make it unique as we may have some equal heights

    for (int i = 0; i < 2 * n; i++) {
        Event event = events[i];
        bool type = event.type;
        int h = event.h;
        int x = event.x;

        int max_h = 0;
        if (type == START) {
            if (!heights.empty()) {
                max_h = (heights.rbegin())->first;
            }
            if (h > max_h) {
                ans.push_back({x, max_h});
                ans.push_back({x, h});
            }
            heights.insert({h, i});
        } else {
            heights.erase(heights.lower_bound(make_pair(h, -1)));
            if (!heights.empty()) {
                max_h = (heights.rbegin())->first;
            }
            if (max_h < h) {
                ans.push_back({x, h});
                ans.push_back({x, max_h});
            }
        }
    }
    cout << ans.size() << endl;
    for (auto p : ans) {
        cout << p.first << space << p.second << endl;
    }

}

int main() {
    solve();
}