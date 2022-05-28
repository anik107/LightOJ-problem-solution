#include<bits/stdc++.h>
using namespace std;
const double e=0.5772156649015328606060651209;
typedef pair<int,int>ii;
typedef pair<ii,int>iii;
typedef long long ll;
const int md=(int)1e9+7;
string a,b,c;
ll dp[65][65][65];
int solve(int i,int j,int k){
    if(i==a.size() || j==b.size() || k==c.size())return 0;
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    if(a[i]==b[j] && b[j]==c[k])return dp[i][j][k]=1+solve(i+1,j+1,k+1);
    return dp[i][j][k]=max(solve(i+1,j,k),max(solve(i,j+1,k),solve(i,j,k+1)));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        cin>>a>>b>>c;
        memset(dp,-1,sizeof(dp));
        cout<<"Case "<<tc<<": "<<solve(0,0,0)<<endl;
    }
}
