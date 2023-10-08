#include<bits/stdc++.h>
using namespace std;
#define INF 1000000
int adj[101][101];
set<int>s;
int caseNo;
void init()
{
    int i,j;
    for(i=1; i<=100; i++)
    {
        for(j=1; j<=100; j++)
        {
            if(i == j)
            {
                adj[i][j]= 0;
            }
            else
            {
                 adj[i][j] = INF;
            }
        }
    }
}
void addEdge(int a,int b)
{
    if(a == b)
    {
        adj[a][b] = 0;
    }
    else
    {
        adj[a][b]=1;
    }
}
void floydWarshall()
{
    int i,j,k;
    for(k=1; k<=100; k++)
    {
        for(i=1; i<=100; i++)
        {
            for(j=1; j<=100; j++)
            {
                if( adj[i][j] > adj[i][k] + adj[k][j] )
            {
                adj[i][j] = adj[i][k] + adj[k][j];
            }
        }
    }
}

}
void  findOutput()
{
    int val = 0,i,j;
    int sz = s.size();
    for(i=1; i<=100; i++)
    {
        for(j=1; j<=100; j++)
        {
            if(adj[i][j]!=INF)
            {
                val += adj[i][j];
            }
        }
    }
    cout<<"Case "<<++caseNo<<": average length between pages = ";
    cout<<fixed<<setprecision(3)<<(float)val/(sz*(sz-1))<<" clicks"<<endl;
}
int main()
{
    int a,b,m,n;
    init();
    while(1)
    {
        cin>>a>>b;
        if(a==0 && b == 0)
        {
            floydWarshall();
            findOutput();
            cin>>m>>n;
            if(m == 0 && n == 0)
            {
                break;
            }
            else
            {
                s.clear();
                init();
                a = m ;
                b = n;
            }
        }
        s.insert(a);
        s.insert(b);
        addEdge(a,b);
    }
}
