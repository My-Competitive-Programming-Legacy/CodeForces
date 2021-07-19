#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cstring>
#include <map>
#include <unordered_set>
#include <cmath>
#include <iomanip>
#include <unordered_map>

typedef long long int ll;
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define linebreak "\n"
#define space " "
#define PI atan(1)*4
#define E 5
#define ACCURATE cout << fixed << setprecision(20)
#define MAX 1e9
#define MOD (int)(1e9 + 7 )
#define ExpMod (int)(1e9 + 6 )
//#define _DEBUG
using namespace std;

//#define _DEBUG

int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IO;
    int n;
    cin >> n;
    vector<int> a;
    //multiset<ll> st;
    map<ll, ll> st;
    ll ex[40];
    for (int i = 0; i < 32; i++) {
        ex[i] = (ll) pow(2, i);
    }
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (st.count(t)) st[t]++;
        else st[t] = 1;
        //st.insert(t);
        a.push_back(t);
    }
    ll debug = 0;
    int rem = 0;
    for (int i = 0; i < n; i++) {
        bool ok = false;
        for (ll j = 0; !ok && j < 32; j++) {
            debug++;
            ll target = ex[j] - a[i];
            if (st.count(target) && ((a[i] == target && st[target] > 1) || a[i] != target)) {
                ok = true;
               // cout << target << "matched with " << a[i] << endl;
            }
        }
        if (!ok) rem++;
    }
    //cout << debug << endl ;
    cout << rem;


    return 0;
}