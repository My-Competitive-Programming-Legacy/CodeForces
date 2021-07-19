#include <bits/stdc++.h>

using namespace std;
#define PI 3.14159265

int main(){
    int n ;
    cin>>n ;
    vector<int>vec(n);
    for(int i =0 ;i <n ; i++){
        cin>>vec[i];
    }
    unsigned long long s = 1 ;
    int o ;
    cin>>o;
    unordered_set<int>ss ;
    for(int i = 0 ; i < n ; i ++){
        if(ss.count(vec[i]))continue;
        ss.insert(vec[i]);
        s*=vec[i];
        s%=o;
    }

    if(s==1||o==1){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}