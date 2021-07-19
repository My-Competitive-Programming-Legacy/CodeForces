#include <bits/stdc++.h>

using namespace std;

struct Dsu {
    vector<int> dsu;
    vector<int> size;
    int n;

    Dsu(int n) {
        this->n = n;
        dsu.resize(n);
        size.resize(n);
    }

    void init() {
        for (int i = 0; i < n; i++) {
            dsu[i] = i;
            size[i] = 1;

        }
    }

    int get_parent(int u) {
        if (dsu[u] == u) return u;
            // path compression
        else
            return dsu[u] = get_parent(dsu[u]);
    }

    bool merge(int u, int v) {
        int pu = get_parent(u);
        assert(pu == u);
        int pv = get_parent(v);

        if (pu == pv)
            return false;

        dsu[pu] = pv;


        return true;
    }


    int count_components() {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (dsu[i] == i) {
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
    int n, m;
    cin >> n >> m;
    Dsu dsu(n + 1);
    dsu.init();
    for (int i = 0; i < m; i++) {
        char type;
        int x;
        cin >> type >> x;
        if (type == '?') {
            int ans = dsu.get_parent(x - 1);
            if(ans == n ) {
                ans = -1 ;
            }else {
                ans += 1 ;
            }
            cout << ans << '\n';
        } else {
            dsu.merge(x - 1, x);
        }
    }
    return 0;
}