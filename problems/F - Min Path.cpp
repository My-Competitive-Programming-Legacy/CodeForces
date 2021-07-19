#include <bits/stdc++.h>

#define ll long long int
using namespace std;

vector<int> dx = {2, 2, -2, -2, 1, -1, 1, -1};
vector<int> dy = {1, -1, 1, -1, 2, 2, -2, -2};


const bool MOD_MODE = false;

template<class type>
class Matrix {
    int n, m;
public:
    vector<vector<type>> mat;

    Matrix(vector<vector<type>> a) {
        this->mat = a;
        this->n = (int) a.size();
        this->m = (int) a[0].size();
    }


public:
    Matrix(int n, int m) {
        this->n = n;
        this->m = m;
        mat.resize(n, vector<type>(m));
    }

    Matrix<type> operator*(Matrix o) {
        // n * m // m * l
        ll INF = 2e18;
        vector<vector<type>> a = mat;
        vector<vector<type>> b = o.mat;
        assert(m == (int) b.size());
        vector<vector<type>> ans(n, vector<type>(b[0].size()));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (int) b[0].size(); j++) {
                ans[i][j] = INF;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (int) b[0].size(); j++) {
//                ans[i][j] = 0;
                for (int k = 0; k < m; k++) {
                    if (!MOD_MODE) {
//                        ans[i][j] += (a[i][k] * b[k][j]);
                        ans[i][j] = min(ans[i][j], mat[i][k] + o.mat[k][j]);
                    } else {

                    }
                }
            }
        }
        return Matrix<type>(ans);
    }

    Matrix<type> exp(long long int b) {
        Matrix<type> ans(n, m);
        Matrix<type> base(mat);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans.mat[i][j] = (i == j);
            }
        }
        while (b > 0) {
            if (b & 1) {
                ans = ans * base;
            }
            base = base * base;
            b >>= 1;
        }

        return ans;
    }
};

#define vi vector<int>
#define vll vector<vector<long long int >>
#define vl vector<long long int >
#define INF  (ll)2e18

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vll g(n, vl(n, INF));
    for (int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        u--;
        v--;
        g[u][v] = cost;
    }
    ll ans = INF;
    Matrix<ll> base(g);
    base = base.exp(k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans = min(ans, base.mat[i][j]);
        }
    }
    if (ans > (ll) 1e18) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << ans << endl;
    }
//    int n;
//    cin >> n;
//    vll a(n , vl(n, 0)) ;
//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++){
//            cin >> a[i][j] ;
//        }
//    }
//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++){
//            for(int k=0;k<n;k++){
//                a[i][j] = min(a[i][j] , )
//            }
//        }
//    }
}