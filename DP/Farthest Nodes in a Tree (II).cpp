#include<bits/stdc++.h>
using namespace std;
const double e=0.5772156649015328606060651209;
typedef long long ll;
vector<pair<int,int>>v[30005];
bool vis[30005];
int dis[30005];
int dis2[30005];
void bfs(int s){
    memset(vis,false,sizeof(vis));
    for(int i=0;i<=30000;i++)dis[i]=0;
    dis[s]=0;
    queue<int>q;
    q.push(s);
    vis[s]=true;
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(auto x: v[now]){
            int next=x.first;
            int cost=x.second;
            if(!vis[next]){
                vis[next]=true;
                dis[next]=dis[now]+cost;
                q.push(next);
            }
        }
    }
}
void bfs2(int s){
    memset(vis,false,sizeof(vis));
    for(int i=0;i<=30000;i++)dis2[i]=0;
    dis2[s]=0;
    queue<int>q;
    q.push(s);
    vis[s]=true;
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(auto x: v[now]){
            int next=x.first;
            int cost=x.second;
            if(!vis[next]){
                vis[next]=true;
                dis2[next]=dis2[now]+cost;
                q.push(next);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        int n;
        cin>>n;
        for(int i=0;i<n-1;i++){
            int a,b,c;
            cin>>a>>b>>c;
            v[a].push_back({b,c});
            v[b].push_back({a,c});
        }
        bfs(0);
        int mx=-INT_MAX;
        int p;
        for(int i=0;i<n;i++){
            if(mx<dis[i]){
                mx=dis[i];
                p=i;
            }
        }
        bfs(p);
        for(int i=0;i<n;i++){
            if(mx<=dis[i]){
                mx=dis[i];
                p=i;
            }
        }
        bfs2(p);
        cout<<"Case "<<tc<<":"<<endl;
        for(int i=0;i<n;i++)cout<<max(dis[i],dis2[i])<<endl;
        for(int i=0;i<=30000;i++)v[i].clear();
    }
}
