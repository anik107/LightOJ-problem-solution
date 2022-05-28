#include<bits/stdc++.h>
using namespace std;
const double e=0.5772156649015328606060651209;
typedef pair<int,int>ii;
typedef pair<ii,int>iii;
typedef long long ll;
const int md=(int)1e9+7;
int n,k;
int a[100005];
int dp[105][105][2];
int solve(int l,int r,int ok){
  if(l>r)return 0;
  if(dp[l][r][ok]!=-1)return dp[l][r][ok];
  int x;
  int sum;
  if(ok==0){
    sum=0;
    x=-numeric_limits<int>::max();
    for(int i=l;i<=r;i++){
        sum+=a[i];
        x=max(x,sum+solve(i+1,r,1));
    }
    sum=0;
    for(int i=r;i>=l;i--){
        sum+=a[i];
        x=max(x,sum+solve(l,i-1,1));
    }
    return dp[l][r][ok]=x;
  }
  if(ok==1){
        sum=0;
        x=numeric_limits<int>::max();
        for(int i=l;i<=r;i++){
            sum+=-a[i];
            x=min(x,sum+solve(i+1,r,0));
        }
        sum=0;
        for(int i=r;i>=l;i--){
            sum+=-a[i];
            x=min(x,sum+solve(l,i-1,0));
        }
        return dp[l][r][ok]=x;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    memset(dp,-1,sizeof(dp));
    cout<<"Case "<<tc<<": "<<solve(0,n-1,0)<<endl;}
}
