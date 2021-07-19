#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define E 10
#define MAX 200000+10
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q ;
    cin >> q ;
    while (q--)  {
       int n  ;
       cin >> n  ;
       vector<pair<int, int>> arr ;
       for(int i = 0 ; i< n ; i++) {
           int a , b ;
           cin >> a >> b ;
           arr.push_back(std::make_pair(a , b)) ;
       }
       sort(arr.begin() , arr.end() );
       bool ok = true ;
       string res="" ;
       for(int i = 0  ; i< arr[0].first ; i++ ) res += "R" ;
       for(int i = 0 ; i< arr[0].second; i++) res +="U" ;
       for(int i = 1 ;i< n ; i++) {
           if(!(arr[i].first >= arr[i-1].first&& arr[i].second >= arr[i-1].second ))
           {
               ok = false ;
               break ;
           }else {
                for(int j  = 0 ;j < (int)(arr[i].first - arr[i-1].first) ; j++)
                    res += 'R'  ;
                for(int j  = 0 ;j < (int)(arr[i].second - arr[i-1].second); j++)
                    res += 'U'  ;
           }
       }
       if(ok ) cout << "YES" << endl << res << endl ;
       else cout << "NO" << endl ;



    }
    return 0;
}