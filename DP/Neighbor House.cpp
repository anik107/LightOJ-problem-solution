#include<bits/stdc++.h>
using namespace std;
const double e=0.5772156649015328606060651209;
typedef pair<int,int>ii;
typedef pair<ii,int>iii;
typedef long long ll;
const int md=(int)1e9+7;
int n,k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        cin>>n;
        int dp[n][3];
        int a,b,c;
        cin>>a>>b>>c;
        dp[0][0]=a;
        dp[0][1]=b;
        dp[0][2]=c;
        for(int i=1;i<n;i++){
            cin>>a>>b>>c;
            dp[i][0]=min(dp[i-1][1],dp[i-1][2])+a;
            dp[i][1]=min(dp[i-1][0],dp[i-1][2])+b;
            dp[i][2]=min(dp[i-1][0],dp[i-1][1])+c;
        }
        cout<<"Case "<<tc<<": "<<min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]))<<endl;
    }
}
