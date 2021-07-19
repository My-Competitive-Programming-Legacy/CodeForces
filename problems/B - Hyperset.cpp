#include <iostream>
#include <vector>
#include <regex>
#include <bits/stdc++.h>


using namespace std;

bool well(string s1, string s2, string s3) {
    int k = (int) s1.length();
    bool ok = true;
    for (int i = 0; i < k; ++i) {
        bool f = s1[i] == s2[i] && s3[i] == s2[i];
        bool l = s1[i] != s2[i] && s3[i] != s2[i];
        if (!(f || l)) { return false; }
    }
    return true;
}

string generate(string s1, string s2) {
    string res = "";
    int k = (int) s1.length();
    for (int i = 0; i < k; ++i) {
        if (s1[i] == s2[i]) res += s1[i];
        else res += 'S' + 'E' + 'T' - s1[i] - s2[i];
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    string s[n + 3];
    unordered_set<string> st;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        st.insert(s[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (st.count(generate(s[i], s[j]))) {
             //   cout << s[i] << "and " << s[j] << " and  "<< generate(s[i] , s[j] ) << endl ;
                res++;
            }
//            for (int k = j+1; k < n; k++) {
//                    if(well(s[i] , s[j] , s[k]))
//                        res++ ;
//            }
        }
    }
    cout << res/3 << endl;


}