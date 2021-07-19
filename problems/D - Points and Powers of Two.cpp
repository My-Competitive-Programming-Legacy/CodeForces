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
    int n;
    cin >> n ;
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        a.push_back(t);
    }
    sort(a.begin() , a.end()) ;
    vector<int> res = {a[0]};
    for (int i = 0; i < n; i++) {
        bool rush = false ;
        for (int j = 0; j < 31; j++){
            bool l = binary_search(a.begin() , a.end()  , a[i] - (1 << j)) ;
            bool r = binary_search(a.begin() , a.end()  , a[i] + (1 << j)) ;
            if(l && r) {
                res = {a[i] - (1 << j) , a[i] ,a[i] + (1 << j)};
                rush = true ;
                break ;
            }else if(l){
                res = {a[i] - (1 << j), a[i]};
            }else if(r) {
                res = {a[i] + (1 << j) , a[i]};
            }
        }
        if(rush ) break ;
    }
    cout << res.size() << endl ;
    for(int i = 0 ; i<(int)res.size() ; i++) cout << res[i] << space ;
    return 0;

}