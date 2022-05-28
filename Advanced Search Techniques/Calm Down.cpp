#include<bits/stdc++.h>
#define pi acos(-1)
using namespace std;
int cnt=0;
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
      double r,n;
      cin>>r>>n;
      double k=r*(sin(pi/n)/(sin(pi/n)+1));
      printf("Case %d: %f\n",i,k);
    }


}
