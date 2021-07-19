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
        int pv = get_parent(v);

        if (pu == pv)
            return false;

        if (size[pu] > size[pv]) {
            swap(pu, pv);
        }
        // the one with larger size is the parent
        // pu -> the smaller size
        dsu[pu] = pv;
        size[pv] += size[pu];
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

    bool same(int u, int v) {
        return get_parent(u) == get_parent(v);
    }
};

struct Query {
    int idx;
    char type;
    int u, v;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q, m;
    cin >> n >> m >> q;
    Dsu dsu(n);
    dsu.init();
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        // have I to use them :D ?
    }
    vector<Query> queries;
    vector<int> ans(q, -1);

    for (int i = 0; i < q; i++) {
        string s;
        int u, v;
        cin >> s >> u >> v;
        queries.push_back({i, s[0], u - 1, v - 1});
    }


    reverse(queries.begin(), queries.end());
    for (int i = 0; i < q; i++) {
        if (queries[i].type == 'a') {
            ans[queries[i].idx] = dsu.same(queries[i].u, queries[i].v);
        } else {
            dsu.merge(queries[i].u, queries[i].v);
        }
    }
    char fendl = '\n' ;
    for(int i=0;i<q;i++){
        if(ans[i] == 0) cout << "NO" << fendl;
        else if(ans[i] == 1 ) cout << "YES" << fendl ;
    }
    return 0;
}