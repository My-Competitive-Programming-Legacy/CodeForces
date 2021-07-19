#include <bits/stdc++.h>
/*
Created on  by Hamza Hassan: 
*/
#define space " "
typedef long long int ll;
#define debug(val) "[ " << #val " : " << (val) << " ]" << space
using namespace std;

void read(vector<int> &a, int n = -1);

void print(vector<int> &a, int n = -1);


void solve() {
    int n, t, k;
    cin >> n >> t >> k;
    auto query = [&](int mb) {
        cout << "? " << 1 << " " << mb + 1 << endl;
        int x;
        cin >> x;
        return (mb + 1 - x);
    };
    int lb = 0, rb = n - 1;
    int ans = 0;
    while (lb <= rb) {
        int mb = (lb + rb) / 2;
        int val = query(mb);

        if (val >= k) {
            ans = mb + 1;
            rb = mb - 1;
        } else {
            lb = mb + 1;
        }

    }
    cout << "! " << ans << endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int qq = 1;
    for (int i = 1; i <= qq; i++) {
        solve();
    }
}

void read(vector<int> &a, int n) {
    if (n == -1) n = a.size();
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void print(vector<int> &a, int n) {
    if (n == -1) {
        n = (int) a.size();
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
}