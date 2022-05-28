#include<bits/stdc++.h>
using namespace std;
const double e=0.5772156649015328606060651209;
typedef pair<int,int>ii;
typedef pair<ii,int>iii;
typedef long long ll;
const int md=(int)1e9+7;
int n,m;
vector<int>g[2*100005];
int together[1000];
int carry[1000];
void bfs(){
    memset(together,0,sizeof(together));
    memset(carry,0,sizeof(carry));
    int cnt=0;
    bool ok;
    queue<int>q;
    q.push(1);
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(auto next: g[now]){
            ok=false;
            if(together[next]==0 && (now==1 || carry[now]==1)){
                together[next]=1;
                ok=true;
            }
            if(carry[next]==0 && together[now]==1){
                cnt++;
                carry[next]=1;
                ok=true;
            }
            if(ok)q.push(next);
        }
    }
    cout<<cnt<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
    cin>>n>>m;
    for(int i=0;i<=n;i++)g[i].clear();
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cout<<"Case "<<tc<<": ";
    bfs();}
}
