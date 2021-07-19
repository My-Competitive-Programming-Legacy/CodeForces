#include <iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define E 10
#define MAX 200000+10
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define space " "

int main() {
    IO;
    ll n , m ;
    cin >> n >> m ;
    vector<ll > arr ;
    arr.push_back(0) ;
    for(int i = 0 ; i < n ; i++ ) {
        ll a ;
        cin >> a ;
        arr.push_back(a + arr[i]) ;
    }
    for(int i = 0  ;i < m ; i++) {
        ll t ;
        cin >> t ;
        //vector<int>::iterator itr ;
        int idx =  upper_bound(arr.begin() ,arr.end() , t) - arr.begin() ;
       // cout << "found at index " << idx << endl ;
        if (arr[idx-1] == t) idx-- ;
        cout << idx << space <<  t - arr[max(idx -1,0) ] << endl ;

    }
}