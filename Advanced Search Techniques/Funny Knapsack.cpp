#include<bits/stdc++.h>
using namespace std;
const double e=0.5772156649015328606060651209;
typedef pair<int,int>ii;
typedef pair<ii,int>iii;
typedef long long ll;
const int md=(int)1e9+7;
vector<ll>a;
vector<ll>b;
vector<ll>ans;
void solve(int i,vector<ll>v,ll sum=0){
    if(i==v.size()){
        ans.push_back(sum);
        return;
    }
    else if(i<v.size()){
        solve(i+1,v,sum);
        solve(i+1,v,sum+v[i]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
    ll n,w;
    cin>>n>>w;
    a.clear();
    b.clear();
    for(int i=1;i<=n;i++){
        ll x;
        cin>>x;
        if(i<=n/2)a.push_back(x);
        else b.push_back(x);
    }
    ans.clear();
    solve(0,a);
    a=ans;
    ans.clear();
    solve(0,b);
    b=ans;
    ll sum=0;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(auto x: a){
        if(x>w)break;
        sum+=upper_bound(b.begin(),b.end(),w-x)-b.begin();
    }
    cout<<"Case "<<tc<<": "<<sum<<endl;}
}
