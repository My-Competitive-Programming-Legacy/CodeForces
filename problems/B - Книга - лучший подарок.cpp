#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"
#include <set>
#include <time.h>
#include <deque>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <memory.h>

using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define PI atan(1)*4
#define pb push_back


void solve() {
    int n , m ;
    cin>>n>>m ;
    int arr[11];
    memset(arr,0,sizeof(arr));
    for(int i = 0; i< n ; i++){
        int num;
        cin>>num;
        arr[num]++;
    }
    ll ans=0;
    for(int i =1;i<=10;i++){
        for(int j = i+1 ; j<=10 ; j++){
            ans+=(arr[i]*1ll*arr[j]);
        }
    }
    cout<<ans<<endl;
}


int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q = 1;
    // cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}