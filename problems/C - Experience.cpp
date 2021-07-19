#include <bits/stdc++.h>

using namespace std;

struct Dsu {
    vector<int> dsu;
    vector<int> size;
    vector<int> good, bad;
    int n;

    Dsu(int n) {
        this->n = n;
        dsu.resize(n);
        size.resize(n);
        good.resize(n);
        bad.resize(n);
    }

    void init() {
        for (int i = 0; i < n; i++) {
            dsu[i] = i;
            size[i] = 1;
            good[i] = bad[i] = 0;
        }
    }

    int get_parent(int u) {
        return dsu[u];
    }

    int get_root(int u) {
        if (dsu[u] == u) return u;
        else return get_root(dsu[u]);
    }

    int get_score(int u) {
        if (dsu[u] == u) {
            assert(bad[u] == false);
            return good[u];
        }
        int ans = -bad[u];
        int score = get_score(dsu[u]);
        return score + good[u] - bad[u];

    }

    void add_score(int u, int delta) {
        int root = get_root(u);
        good[root] += delta;
    }

    bool merge(int u, int v) {
        int pu = get_root(u);
        int pv = get_root(v);
        assert(bad[pu] == 0);
        assert(bad[pv] == 0);
        if (pu == pv)
            return false;

        if (size[pu] > size[pv]) {
            swap(pu, pv);
        }
        // the one with larger size is the parent
        // pu -> the smaller size
        dsu[pu] = pv;
        bad[pu] = good[pv];
        size[pv] += size[pu];
        return true;
    }


    int count_components() {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (get_root(i) == i) {
                ans += 1;
            }
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    Dsu dsu(n);
    dsu.init();
    while (q--) {
        string s;
        int u;
        cin >> s >> u;
        u -= 1;
        if (s[0] == 'a') {
            int val;
            cin >> val;
            dsu.add_score(u, val);
        } else if (s[0] == 'j') {
            int v ;
            cin >> v ;
            v-=1 ;
            dsu.merge(u , v ) ;
        } else {
            cout << dsu.get_score(u) << '\n';
        }
    }
    return 0;
}