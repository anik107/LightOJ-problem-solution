#include<bits/stdc++.h>
using namespace std;
const double e=0.5772156649015328606060651209;
typedef long long ll;
const int md=(int)1e9+7;
int n,m;
ll a[2*100005];
bool solve(int k){
    ll sum=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum>k){
            cnt++;
            sum=a[i];
        }
    }
    if(sum>0)cnt++;
    return cnt<=m;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        cin>>n>>m;
        ll l=numeric_limits<ll>::min();
        ll r=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            l=max(l,a[i]);
            r+=a[i];
        }
        while(l<r){
            ll mid=l+(r-l)/2;
            if(solve(mid))r=mid-1;
            else l=mid+1;
        }
        ll ans=l;
        cout<<"Case "<<tc<<": ";
        if(solve(ans))cout<<ans<<endl;
        else cout<<ans+1<<endl;
    }
}
