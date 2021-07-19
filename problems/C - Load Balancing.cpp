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
    int n ;
    cin>>n ;
    int arr[n+2];
    ll sum=0;

    for(int i =0; i< n ; i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    ll target=sum/n;
    ll ans=0;
    for(int i =0; i < n ; i++){
        if(arr[i]<target){
            ans+=abs(arr[i]-target);
        }
    }
    if(sum%n==0){
        cout<<ans<<endl;
        return;
    }
  ans=0;
    ll ans2=0;
    for(int i =0 ;i<n ; i++){
        if(arr[i]>target){
            ans+=(arr[i]-target-1);
        }else{
            ans2+=(target-arr[i]);
        }
    }
    cout<<max(ans,ans2)<<endl;
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