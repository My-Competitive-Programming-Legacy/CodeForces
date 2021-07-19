#include <bits/stdc++.h>

using namespace std;
#define endll '\n'
#define ar array
#define space ' '
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
const int mxN = 1e5, mxM = 1e5;
const int MOD = 1e9 + 7;
mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int n = 6;
int m_n = 0;
map<vector<int>, int > all ;
struct grid {
    vector<vector<int>> vec;
    vector<int>rep;
    int depth;

    grid(int dep) {
        vec.resize(6, vector<int>(6));
        rep.resize(11);
        depth = dep;
    }

    grid(vector<vector<int>> &se, int de , vector<int>rr) {
        vec.resize(6, vector<int>(6));
        rep.resize(11);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                vec[i][j] = se[i][j];
            }
        }
        depth = de ;
        for(int i = 1 ; i <= 10 ; i ++){
            rep[i]=rr[i];
        }
    }


    void read() {
        rep.resize(11);
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                cin >> vec[i][j];
                m_n = max(m_n, vec[i][j]);
            }
        }

    }

    bool same(grid s) {
        for (int i = 1; i <=10 ; i++) {
           if(rep[i]!=s.rep[i])return false;
        }
        return true;
    }

};



bool can_left(grid s, vector<pair<int, int>> cur, int num) {
    for (auto it : cur) {
        if (it.second == 0)return false;
        if (s.vec[it.first][it.second - 1] != 0 && s.vec[it.first][it.second - 1] != num) {
            return false;
        }
    }
    int nn = cur.size();
    for (int i = 0; i < nn - 1; i++) {
        if (cur[i].first != cur[i + 1].first)return false;
    }
    return true;
}
grid move_left(grid s, vector<pair<int, int>> cur, int num) {
    grid g(s.vec, s.depth + 1,s.rep);
    for (auto it : cur) {
        g.vec[it.first][it.second] = 0;
    }
    for (auto it : cur) {
        g.vec[it.first][it.second - 1] = num;
    }
    g.rep[num]--;

    return g;

}

bool can_right(grid s, vector<pair<int, int>> cur, int num) {
    for (auto it : cur) {
        if (it.second == 5)return false;
        if (s.vec[it.first][it.second + 1] != 0 && s.vec[it.first][it.second + 1] != num) {
            return false;
        }
    }
    int nn = cur.size();
    for (int i = 0; i < nn - 1; i++) {
        if (cur[i].first != cur[i + 1].first)return false;
    }

    return true;
}

grid move_right(grid s, vector<pair<int, int>> cur, int num) {
    grid g(s.vec, s.depth + 1,s.rep);
    for (auto it : cur) {
        g.vec[it.first][it.second] = 0;
    }
    for (auto it : cur) {
        g.vec[it.first][it.second + 1] = num;
    }
    g.rep[num]++;
    return g;

}

bool can_up(grid s, vector<pair<int, int>> cur, int num) {
    for (auto it : cur) {
        if (it.first == 0)return false;
        if (s.vec[it.first - 1][it.second] != 0 && s.vec[it.first - 1][it.second] != num) {
            return false;
        }
    }
    int nn = cur.size();
    for (int i = 0; i < nn - 1; i++) {
        if (cur[i].second != cur[i + 1].second)return false;
    }
    return true;
}

grid move_up(grid s, vector<pair<int, int>> cur, int num) {
    grid g(s.vec, s.depth + 1,s.rep);
    for (auto it : cur) {
        g.vec[it.first][it.second] = 0;
    }
    for (auto it : cur) {
        g.vec[it.first - 1][it.second] = num;
    }
    g.rep[num]++;

    return g;

}

bool can_down(grid s, vector<pair<int, int>> cur, int num) {
    for (auto it : cur) {
        if (it.first == 5)return false;
        if (s.vec[it.first + 1][it.second] != 0 && s.vec[it.first + 1][it.second] != num) {
            return false;
        }
    }
    int nn = cur.size();
    for (int i = 0; i < nn - 1; i++) {
        if (cur[i].second != cur[i + 1].second)return false;
    }

    return true;
}

grid move_down(grid s, vector<pair<int, int>> cur, int num) {
    grid g(s.vec, s.depth + 1,s.rep);
    for (auto it : cur) {
        g.vec[it.first][it.second] = 0;
    }
    for (auto it : cur) {
        g.vec[it.first + 1][it.second] = num;
    }
    g.rep[num]--;
    return g;

}
bool unique(grid s){
    return all[s.rep]==0;
}

void solve() {
    queue<grid> bfs;
    grid s(0);
    s.read();
    bfs.push(s);
    all[s.rep]=true;
    int nnnn = 0 ;
   while (bfs.size()) {
        grid last = bfs.front();
        bfs.pop();
        if (last.vec[2][5] == 1 && last.vec[2][4] == 1) {
            cout << last.depth + 2 << endl;
            exit(0);
        }

        if (last.depth >= 8)continue;
        for (int i = 1; i <= m_n; i++) {
            vector<pair<int, int >> cur;
            for (int ii = 0; ii < 6; ii++) {for (int j = 0; j < 6; j++) {if (last.vec[ii][j] == i) {cur.push_back({ii, j});}}}
            if (can_left(last, cur, i)) {
                grid next = move_left(last, cur, i);
                if(unique(next)){
                    bfs.push(next);
                    all[next.rep]=true;

                }
            }
            if (can_right(last, cur, i)) {
                grid next = move_right(last, cur, i);
                if(unique(next)){
                    bfs.push(next);
                    all[next.rep]=true;

                }

            }
            if (can_up(last, cur, i)) {
                grid next = move_up(last, cur, i);
                if(unique(next)){
                    bfs.push(next);
                    all[next.rep]=true;


                }
            }
            if (can_down(last, cur, i)) {
                grid next = move_down(last, cur, i);
                if(unique(next)){
                    bfs.push(next);
                    all[next.rep]=true;

                }
            }

        }
    }
    cout << -1 << endl;

}

int main() {
    IO;
    int t = 1; //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}