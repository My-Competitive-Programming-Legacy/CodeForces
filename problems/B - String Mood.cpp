#include <bits/stdc++.h>
using namespace std;
const bool MOD_MODE = true;
const int Mod = (int) 1e9 + 7;

template<class type>
class Matrix {
    int n, m;
public:
    vector<vector<type>> mat;

private:
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
        vector<vector<type>> a = mat;
        vector<vector<type>> b = o.mat;
        assert(m == (int) b.size());
        vector<vector<type>> ans(n, vector<type>(b[0].size()));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (int) b[0].size(); j++) {
                ans[i][j] = 0;
                for (int k = 0; k < m; k++) {
                    if (!MOD_MODE) {
                        ans[i][j] += (a[i][k] * b[k][j]);
                    } else {
                        ans[i][j] += ((int) a[i][k] *1LL* (int) b[k][j]) % Mod;
                        ans[i][j] %= Mod ;
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


int main() {
//    cout << fixed << setprecision(20);
    long long int n;
    cin >> n;
//    cin >> n >> p;
    Matrix< int> base(2, 2);
    base.mat = {{19, 6},
                {7,  20}};

    base = base.exp(n);
    vector<vector<int>> ans = base.mat;

    cout << ans[0][0] << endl;
}