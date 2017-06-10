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

int checkbp(vector < vi > g){
        int n = g.size(), count=0;
        vi v(n,0);
        rep(i,n){
            if(v[i] == 0){
                count++;
                cout << count << endl;
                v[i] = 1;
                vi q; q.pb(i);
                while(!q.empty()){
                    q.erase(q.begin());
                    for(auto adj:g[q.front()]){
                        if(v[adj] == 0){
                            v[adj] = -v[q.front()];
                            q.pb(adj);
                        }
                        else{
                            if(v[q.front()] == v[adj]){
                                return 0;
                            }
                        }
                    }
                }
            }
        }
        return 1;
}

int main(){
    std::ios_base::sync_with_stdio(false);
        int n,t;
        cin >> t;
        rep(i,t){
            int m; cin >> n >> m;
            vector< vi > g(n);
            rep(i,m){
                int v1,v2; cin >> v1 >> v2; v1--; v2--;
                g[v1].pb(v2);
                g[v2].pb(v1);
            }
            int bp = 0;
            bp = checkbp(g);
            cout << "Scenario #" << i+1 << ":" << endl;
            if(bp){
                cout << "No suspicious bugs found!" << endl;
            }
            else {
                cout << "Suspicious bugs found!" << endl;
            }
        }

    return 0;
}

