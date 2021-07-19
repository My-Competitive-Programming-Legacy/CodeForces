#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <cmath>

using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define pb push_back

int main() {
    int n, I, K = -1;
    cin >> n >> I ;
    int dis = 0;
    for (int j = n; j >= 0; j--) {
        if (ceil((double) log2(j)) * n <= I * 8) {
            K = j;
            break;
        }
    }
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (!mp.count(t)) {
            dis++;
            mp[t] = 1;
        } else mp[t]++;
    }
    vi a;
    for (auto i : mp) {
        a.push_back(i.second);
    }
    if(dis <= K ) {
        cout << 0 << endl ;
        return 0 ;
    }
    for(int i = 1 ; i < (int)a.size() ; i++ ){
        a[i] += a[i-1];
    }
    int with = a[K-1] ;
    for(int i = K  ; i < (int)a.size() ; i++ ){
        with = max(with , a[i] - a[i - K  ]) ;
    }
    cout << a[(int)a.size() -1 ]  - with << endl ;

    return 0;

}