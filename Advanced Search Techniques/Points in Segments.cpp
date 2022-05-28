#include<bits/stdc++.h>
using namespace std;
const double e=0.5772156649015328606060651209;
typedef long long ll;
const int md=(int)1e9+7;
int n,m;
ll a[2*100005];
ll b[2*100005];
ll tree[2*100005];
void update(int idx,int val){
    while(idx<=n){
        tree[idx]+=val;
        idx+=idx&-idx;
    }
}
ll query(int idx){
    ll sum=0;
    while(idx>0){
        sum+=tree[idx];
        idx-=idx&-idx;
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
    for(int i=0;i<=100005;i++)tree[i]=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    set<ll>s;
    for(int i=0;i<n;i++)s.insert(a[i]);
    int idx=0;
    for(auto x: s)b[idx++]=x;
    for(int i=0;i<n;i++)a[i]=lower_bound(b,b+idx,a[i])-b+1;
    for(int i=0;i<n;i++){
        update(a[i],1);
    }
    cout<<"Case "<<tc<<":"<<endl;
    while(m-->0){
        int l,r;
        cin>>l>>r;
        int lo=lower_bound(b,b+idx,l)-b;
        int hi=lower_bound(b,b+idx,r)-b;
        if(hi>idx)hi--;
        if(b[hi]==r)cout<<query(hi+1)-query(lo)<<endl;
        else cout<<query(hi)-query(lo)<<endl;
    }
    }
}
