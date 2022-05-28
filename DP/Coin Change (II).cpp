#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define leading zero str.erase(0, min(str.find_first_not_of('0'), str.size()-1));
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
string text="abcdefghijklmnopqrstuvwxyz";
const int maxn=1e6+7;
//        .--------------.
//        | Try First One|
//        '--------------'
//                |     .--------------.
//                |     |              |
//                V     V              |
//              .--------------.       |
//              |      AC.     |<---.  |
//              '--------------'    |  |
//              (True)|  |(False)   |  |
//           .--------'  |          |  |
//           |           V          |  |
//           |  .--------------.    |  |
//           |  |   Try Again  |----'  |
//           |  '--------------'       |
//           |                         |
//           |  .--------------.       |
//           '->| Try Next One |-------'
//              '--------------'
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
    int n,m;
    cin>>n>>m;
    int a[n+2];
    for(int i=1; i<=n; i++)
        cin>>a[i];
    int dp[n+1][m+1];

    for(int i = 1; i <= n; i++)
    {
        for(int sum = 0; sum <= m; sum++)
        {
            if(sum == 0)
                dp[i][sum] = 1;
            else
            {
                int op1 = (a[i] > sum) ? 0 : dp[i][sum - a[i]];
                int op2 = (i == 1) ? 0 : dp[i-1][sum];
                dp[i][sum] = (op1 + op2)%100000007;
            }
        }
    }
    cout<<"Case "<<tc<<": "<<dp[n][m]<<endl;}
}
