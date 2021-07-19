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

typedef long long int ll;
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define linebreak "\n"
#define space " "
#define PI atan(1)*4
#define E 5
#define ACCURATE cout << fixed << setprecision(20)
#define MAX 1e9
#define MOD (int)(998244353 )
//#define _DEBUG
using namespace std;

int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IO;
    int n, m;
    cin >> n >> m;
    int arr[n + E];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    if (m == n) {
        cout << (int)1e9 ; 
    }
    else if (m == 0 ) {
        if(arr[0] == 1 ) cout << -1 ; else cout << 1 ;
    }
    else {
        if(m<n && arr[m-1] == arr[m]) cout << -1 ; else cout << arr[m-1] ;
    }
    return 0;
}
