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
//struct SCC{
//    int n;vector<vector<int>>g,rg;vector<int>todo,comp,comps;
//    vector<bool>vis;
//    void init(int _n){
//       n=_n;
//       g.resize(n);rg.resize(n);vis.resize(n);
//       comp=vector<int>(n,-1);
//    }
//    void ae(int a,int b){
//        g[a].push_back(b);
//        rg[b].push_back(a);
//    }
//    void dfs(int now){
//        vis[now]=1;
//        for(auto next: g[now])if(!vis[next])dfs(next);
//        todo.push_back(now);
//    }
//    void dfs2(int now,int par){
//        comp[now]=par;
//        for(auto next: rg[now])if(comp[next]==-1)dfs2(next,par);
//    }
//    void gen(){
//        for(int i=0;i<n;i++)if(!vis[i])dfs(i);
//        reverse(todo.begin(),todo.end());
//        for(auto x: todo){
//            if(comp[x]==-1){
//                dfs2(x,x);
//                comps.push_back(x);
//            }
//        }
//    }
//};
const int mxn=100005;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,tc=0;
    cin>>t;
    while(t-->0){
        int n;
        cin>>n;
        vector<vector<int>>g;
        g.resize(mxn);
        int in[mxn]={0};
        map<string,int>mp;
        int cnt=0;
        for(int i=0;i<n;i++){
            string a,b;
            cin>>a>>b;
            if(!mp.count(a))mp[a]=cnt++;
            if(!mp.count(b))mp[b]=cnt++;
            g[mp[a]].push_back(mp[b]);
            in[mp[b]]++;
        }
        queue<int>q;
        vector<int>order;
        for(int i=0;i<cnt;i++)if(in[i]==0)q.push(i);
        while(!q.empty()){
            int now=q.front();
            q.pop();
            order.push_back(now);
            for(auto next: g[now]){
                in[next]--;
                if(in[next]==0)q.push(next);
            }
        }
        cout<<"Case "<<++tc<<": "<<((cnt!=(int)order.size())?"No":"Yes")<<endl;
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
