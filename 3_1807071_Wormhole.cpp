#include<bits/stdc++.h>
using namespace std;
int n,m;
class graph
{
 public:
  int x;
  int y;
  int t;
};
graph grp[2000];
int src= 0;
bool findPossible()
{
 int dst[n];
 int i,j;
 dst[src]=0;
 for(i=1;i<n;i++)
 {
   dst[i]=INFINITY;
 }
 for(i=0;i<(n-1);i++)
 {
   for(j=0;j<m;j++)
   {
      if(dst[grp[j].y]>(dst[grp[j].x]+grp[j].t))
      {
        dst[grp[j].y]=dst[grp[j].x]+grp[j].t;
      }
   }
 }
 for(i=0;i<m;i++)
 {
     if(dst[grp[i].y]>(dst[grp[i].x]+grp[i].t))
         return true;
 }
 return false;
}
int main()
{
  int c,x,y,t,i,j;
  cin>>c;
  for(i=0;i<c;i++)
  {
    cin>>n>>m;
    for(j=0;j<m;j++)
    {
      cin>>x>>y>>t;
      grp[j].x=x;
      grp[j].y=y;
      grp[j].t=t;

    }
    if(findPossible())
    {
        cout<<"possible"<<endl;
    }
    else
    {
        cout<<"not possible"<<endl;
    }
  }

}

