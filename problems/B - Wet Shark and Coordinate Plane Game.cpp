#include <bits/stdc++.h>

using namespace std;
#define PI 3.14159265

int main() {
    int n ;
    cin>>n ;
    vector<pair<int , int>>a , b ;
    int t0,t1,t2;
    for(int i = 0 ; i < n ; i ++){
        cin>>t0>>t1>>t2;
        if(t0==1){
            a.push_back({t1,t2});
        }else{
            b.push_back({t1,t2});
        }
    }
    sort(a.begin(),a.end(),[&](pair<int , int>aa , pair<int , int>bb){
        return aa.first - aa.second > bb.first - bb.second;
    });
    sort(b.begin(),b.end(),[&](pair<int , int>aa , pair<int , int>bb){
        return aa.first - aa.second > bb.first - bb.second;
    });
    int x  = 1 , y = 1 ;
    for(auto it : a){
        x+=it.first ;
        x-=it.second;
        if(x<=0){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    for(auto it : b){
        y+=it.first ;
        y-=it.second;
        if(y<=0){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    cout<<"("<<x<<", "<<y<<")";

}