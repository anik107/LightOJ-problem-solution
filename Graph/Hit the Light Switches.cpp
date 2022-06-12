#include<bits/stdc++.h>
using namespace std;
const double e=0.5772156649015328606060651209;
typedef pair<int,int>ii;
typedef pair<ii,int>iii;
typedef long long ll;
const int md=(int)1e9+7;
int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char path[]={'D','U','R','L'};
const ll lim=1e18;
struct SCC{
    int n,cnt;vector<vector<int>>g;vector<int>todo;
    vector<bool>vis,vis2;
    void init(int _n){
       n=_n;
       cnt=0;
       g.resize(n);vis.resize(n);vis2.resize(n);
    }
    void ae(int a,int b){
        g[a].push_back(b);
    }
    void dfs(int now){
        vis[now]=1;
        for(auto next: g[now])if(!vis[next])dfs(next);
        todo.push_back(now);
    }
    void dfs2(int now){
        vis2[now]=1;
        for(auto next: g[now])if(!vis2[next])dfs2(next);
    }
    void gen(){
        for(int i=0;i<n;i++)if(!vis[i])dfs(i);
        reverse(todo.begin(),todo.end());
        for(auto x: todo){
            if(!vis2[x]){
                cnt++;
                dfs2(x);
            }
        }
    }
};
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,tc=0;
    cin>>t;
    while(t-->0){
        SCC graph;
        int n,m;
        cin>>n>>m;
        graph.init(n);
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            a--;b--;
            graph.ae(a,b);
        }
        graph.gen();
        cout<<"Case "<<++tc<<": "<<graph.cnt<<endl;
    }
}
/*
7 9
1 2
2 1
1 4
2 5
5 4
3 2
3 7
7 6
6 3
*/
