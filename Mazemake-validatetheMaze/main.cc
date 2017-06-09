#include <bits/stdc++.h>

#define all(c) c.begin(), c.end()
#define LL long long
#define pb push_back
#define vi vector<int>
#define vll vector<LL>
#define rep(i,n)    for(__typeof(n) i = 0; i < n; i++)
#define rep1(i,n)   for(__typeof(n) i = 1; i <= n; i++)

using namespace std;

int in;
vector<pair <int,int> > way;

int bfs(vector< vector<char> > maze, vector< pair <int,int> > bound){
      vector< pair <int,int> > q;
      q.pb(bound.front());

      while(!q.empty()){
          int j,k; j = q.front().first; k = q.front().second; //cout << j << k << " ";
          if(q.front() == bound.back()) return 1;
          q.erase(q.begin());
          auto p1 = make_pair(j,k-1);
          auto p2 = make_pair(j,k+1);
          auto p3 = make_pair(j-1,k);
          auto p4 = make_pair(j+1,k);
          if(find(all(way), p1) != way.end()) q.pb(p1);
          if(find(all(way), p2) != way.end()) q.pb(p2);
          if(find(all(way), p3) != way.end()) q.pb(p3);
          if(find(all(way), p4) != way.end()) q.pb(p4);
      }
    return 0;
}

int main(){
    std::ios_base::sync_with_stdio(false);
        int n,t;
        cin >> t;
        rep(i,t){
            int m,n,valid=0; cin >> m >> n;
            vector< vector<char> > maze(m, vector<char> (n));
            vector<pair <int,int> > bound;
            rep(j,m){
                rep(k,n){
                    char c; cin >> c; maze[j].pb(c);
                    if(c == '.') {
                        way.pb(make_pair(j,k));
                         if(j == 0 || k == 0 || j == m-1 || k == n-1){
                            bound.pb(make_pair(j,k));
                        }
                    }
                }
            }

           // for(auto p:way) cout << p.first << p.second << " ";
            if(bound.size() != 2) goto ans;
            valid = bfs(maze,bound);
ans :
            cout << (valid ? "valid" : "invalid") << endl;
            way.clear();
        }

    return 0;
}

