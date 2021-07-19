#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cstring>
#include <map>
#include <unordered_set>

#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int ll;
#define linebreak "\n"
#define space " "
#define E 10
#define MAX 2e9+10
#define MOD (int)1e9
using namespace std;

//#define _DEBUG
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IO;
    int n, k;
    cin>>n >>k;
    string s ;
    cin>>s;
    map<char , vector<int>> m ;
    for(int i=0;i<s.size();i++){
        m[s[i]].push_back(i);
    }
    unordered_set<int> zayady;
    char p ='a';
    while (k>0){
        while (m[p].size()==0)p++;
        if(p=='z'+1)break;
        for(int i=0;i<m[p].size();i++){
            if(k==0)break;
            k--;
            zayady.insert(m[p][i]);
        }
        p++;
    }
    for(int i=0;i<s.size();i++){
        if(zayady.count(i))continue;
        cout<<s[i];
    }

    return 0;
}