//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define E 10
#define MAX 200000+10
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define space " "
typedef long long int ll;
using namespace std;
int main() {
    IO;
    int q ;
    cin >> q ;
    while(q-- ) {
        int n ;
        cin >> n ;
        string s ;
        cin >> s ;
        int odd = 0 ;
        for(int i = 0 ; i<(int)s.size() ; i++) {
            if((s[i] - '0') %2 == 1) {
               odd ++ ;
            }
        }
//        if(!odd || (int)s.size() == 1) {
//            cout << -1 << endl;
//            continue ;
//        }
        bool ok = false  ;
        for(int i = n-1 ;i>=0 ; i--){
            if(s[i] %2  ) {
                if(odd %2 == 0 ){
                    ok  =true ;
                    cout << s.substr(0 , i+1) << endl ;
                    break;
                }else {
                    odd -- ;
                }
            }
        }
        if(!ok ) {
            cout << -1 << endl ;
        }


    }



}