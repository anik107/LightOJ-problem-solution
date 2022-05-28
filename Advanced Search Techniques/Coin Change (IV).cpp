#include<bits/stdc++.h>
using namespace std;
const double e=0.5772156649015328606060651209;
typedef pair<int,int>ii;
typedef pair<ii,int>iii;
typedef long long ll;
const int md=(int)1e9+7;
vector<int>a;
vector<int>b;
vector<int>sum1;
vector<int>sum2;
void solve(int i,int n,int tot,vector<int> &a,vector<int> &sum){
    sum.push_back(tot);
    if(i<n){
        solve(i+1,n,tot,a,sum);
        solve(i+1,n,tot+a[i],a,sum);
        solve(i+1,n,tot+2*a[i],a,sum);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
    int n,k;
    cin>>n>>k;
    a.clear();
    b.clear();
    sum1.clear();
    sum2.clear();
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(i&1)b.push_back(x);
        else a.push_back(x);
    }
    solve(0,a.size(),0,a,sum1);
    solve(0,b.size(),0,b,sum2);
    sort(sum1.begin(),sum1.end());
    sort(sum2.begin(),sum2.end());
    sum1.erase(unique(sum1.begin(),sum1.end()),sum1.end());
    sum2.erase(unique(sum2.begin(),sum2.end()),sum2.end());
    bool ok=false;
    for(auto x: sum1){
        if(k<x)break;
        int val=k-x;
        int l=0,r=sum2.size();
        while(l<r){
            int mid=l+(r-l)/2;
            if(sum2[mid]>val)r=mid;
            else l=mid+1;
        }
        if(sum2[l]==val || sum2[l-1]==val){
            ok=true;
            break;
        }
    }
    cout<<"Case "<<tc<<": ";
    if(ok)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;}
}
