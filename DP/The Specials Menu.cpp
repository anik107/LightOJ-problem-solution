#include<bits/stdc++.h>
using namespace std;
const double e=0.5772156649015328606060651209;
typedef pair<int,int>ii;
typedef pair<ii,int>iii;
typedef long long ll;
const int md=(int)1e9+7;
string s;
ll dp[100][100];
ll solve(int i,int j){
    if(i>j)return 0;
    if(i==j)return 1;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==s[j])return dp[i][j]=1+solve(i+1,j)+solve(i,j-1);
    return dp[i][j]=solve(i+1,j)+solve(i,j-1)-solve(i+1,j-1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        cin>>s;
        memset(dp,-1,sizeof(dp));
        cout<<"Case "<<tc<<": "<<solve(0,s.size()-1)<<endl;
    }
}
