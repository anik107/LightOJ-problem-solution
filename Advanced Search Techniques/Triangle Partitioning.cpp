#include<bits/stdc++.h>
using namespace std;

int main()
{
   int t;
   cin>>t;
   for(int i=1;i<=t;i++){
    double ab,bc,ac,area;
    cin>>ab>>ac>>bc>>area;
    double k=sqrt(area/(area+1));
    printf("Case %d: %f\n",i,k*ab);}

}
