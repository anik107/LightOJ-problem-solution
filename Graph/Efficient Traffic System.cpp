#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int n,m;
struct SCC{
    vector<vector<int>>g,rg;vector<int>todo,comp,comps;
    vector<bool>vis;int n;
    void init(int _n){
        n=_n;
        g.resize(n);rg.resize(n);vis.resize(n);
        comp=vector<int>(n,-1);
    }
    void ae(int a,int b){
        g[a].push_back(b);
        rg[b].push_back(a);
    }
    void dfs(int now){
        vis[now]= true;
        for(auto next: g[now]){
            if(!vis[next])dfs(next);
        }
        todo.push_back(now);
    }
    void dfs2(int now,int par) {
        comp[now] = par;
        for (auto next: rg[now]) {
            if (comp[next] == -1)dfs2(next, par);
        }
    }
    void gen(){
        for(int i=0;i<n;i++){
            if(!vis[i])dfs(i);
        }
        reverse(todo.begin(),todo.end());
        for(auto x: todo) {
            if (comp[x] == -1) {
                dfs2(x, x);
                comps.push_back(x);
            }
        }
    }
};
vector<vector<int>>final;
int in[5*100005],out[5*100005];
bool vis[5*100005];
void dfs(int now){
    vis[now]= true;
    for(auto next: final[now]){
        in[next]++;
        out[now]++;
        if(!vis[next])dfs(next);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++) {
        SCC graph;
        cin >> n >> m;
        graph.init(n);
        vector<pair<int, int>> v;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            v.push_back({a, b});
            graph.ae(a, b);
        }
        graph.gen();
        int sz=graph.comps.size();
        cout << "Case "<<tc<<": ";
        if(sz==1){
            cout<<"0"<<endl;
            continue;
        }
        final.resize(n);
        for(int i=0;i<n;i++){
            in[i]=0;
            out[i]=0;
            vis[i]= false;
            final[i].clear();
        }
        for (auto x: v) {
            int a = x.first;
            int b = x.second;
            if (graph.comp[a] != graph.comp[b]) {
                final[graph.comp[a]].push_back(graph.comp[b]);
            }
        }
        for (auto x: graph.comps) {
            if (!vis[x]) {
                dfs(x);
            }
        }
        int inrevcnt = 0;
        int outrevcnt = 0;
        for (auto x: graph.comps) {
            if (!in[x])inrevcnt++;
            if (!out[x])outrevcnt++;
        }
        cout <<max(inrevcnt, outrevcnt) << endl;
    }
    return 0;
    /*
     * 7 10
        1 2
        2 1
        1 4
        2 5
        5 4
        3 2
        6 5
        6 3
        3 7
        7 6
     */
}
