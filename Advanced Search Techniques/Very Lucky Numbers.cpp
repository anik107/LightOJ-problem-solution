#include<bits/stdc++.h>
using namespace std;
const double e=0.5772156649015328606060651209;
typedef long long ll;
vector<ll>lucky;
set<ll>s;
void solve(ll cur,int idx,int sz){
    if(cur!=1 && cur!=0)s.insert(cur);
    for(int i=idx;i<sz;i++){
        if(cur*lucky[i]<=1e12 && cur*lucky[i]>0)solve(cur*lucky[i],i,sz);
        else break;
    }
}
int main(){
    queue<ll>q;
    q.push(4);
    q.push(7);
    while(!q.empty()){
        ll x=q.front();
        q.pop();
        if(x>1e12)break;
        lucky.push_back(x);
        q.push(x*10+4);
        q.push(10*x+7);
    }
    solve(1,0,lucky.size());
    lucky.clear();
    for(auto x: s)lucky.push_back(x);
    sort(lucky.begin(),lucky.end());
    lucky.erase(unique(lucky.begin(),lucky.end()),lucky.end());
    //cout<<lower_bound(lucky.begin(),lucky.end(),100)-lucky.begin()<<endl;
    //for(auto x: lucky)cout<<x<<" ";
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        ll a,b;
        cin>>a>>b;
        ll ans=0;
        int id1=lower_bound(lucky.begin(),lucky.end(),a)-lucky.begin();
        int id2=lower_bound(lucky.begin(),lucky.end(),b)-lucky.begin();
        ans=id2-id1;
        if(lucky[id2]==b)ans++;
        cout<<"Case "<<tc<<": "<<ans<<endl;
    }
}
