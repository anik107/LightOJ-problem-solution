#include<bits/stdc++.h>
using namespace std;
const double e=0.5772156649015328606060651209;
typedef pair<int,int>ii;
typedef pair<ii,int>iii;
typedef long long ll;
const int md=(int)1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        ll n,k;
        cin>>n>>k;
        map<ll,ll>mp;
        mp[0]=1;
        ll sum=0;
        ll ans=0;
        for(int i=0;i<n;i++){
            ll x;
            cin>>x;
            sum+=x;
            ans+=mp[sum%k];
            mp[sum%k]++;
        }
        cout<<"Case "<<tc<<": "<<ans<<endl;
    }
}
