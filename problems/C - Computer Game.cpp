#include <iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define E 10
#define MAX 200000+10
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q;
    cin >> q;
    while (q--)
    {
        ll n , k , a , b ;
        cin >> n >>k>>a >>  b ;
        ll res = -1 ;
        ll l = 0 , r = k ;

        while(r>=l ){
            ll mid = l + (r - l)/2 ;
            if(a*mid + b*(k - mid) < n){
                res = max (res,  mid) ;
                l = mid+1 ;
            }else {
                r = mid -1 ;
            }

        }
        cout << res  << endl ;
    }


    return 0;
}