#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endll "\n"
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll INF = 1e15;
const int N = 3e3 + 2;


int main() {
    IO;
    int n ;
    cin>>n ;
    if(n%2==0){
        return cout<<"NO",0;
    }
    int num = n *2 ;
    ll all = 1ll*num*(num+1)/2;
    vector<int>vec;
    int pre = 1 ;
    int cur = 0 ;
    int here = all / 2 ;
    for(int i = 0 ; i< n ; i++){
        vec.push_back(pre);
        if(i%2==0){
            pre+=3;
        }else{
            pre++;
        }
    }
    bool f =true;
    while (vec.size()!=n*2){
        if(f){
            vec.push_back(vec[vec.size()-n] + 1 );
        }else{
            vec.push_back(vec[vec.size()-n] - 1 );
        }
        f=!f;
    }
    cout<<"YES"<<endl;
    for(int num : vec){
        cout<<num<<" ";
    }
    cout<<endl;


}