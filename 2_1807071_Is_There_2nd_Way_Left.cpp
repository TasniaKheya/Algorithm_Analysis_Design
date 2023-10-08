#include<bits/stdc++.h>
#define INF 10000000
using namespace std;
int parent[210];
int visited[210];
int serial=0,node,edge;
class graphEdge
{
    public:
    int src;
    int dest;
    int wgt;
};
graphEdge graph[210];
bool comp(graphEdge gE1, graphEdge gE2)
{
    return gE1.wgt < gE2.wgt;
}
void makeParent()
{
    int i;
    for(i=1; i<=node; i++)
    {
        parent[i] = i;
    }
}
int findP(int n)
{
    if(parent[n] == n)
    {
        return n;
    }
    else
    {
        return findP(parent[n]);
    }
}
void find2ndBest(int check)
{
    int sBest = INF,i,sum2,check2,j,srcP,destP;
    graphEdge gE;
    for(i = 1; i <= check ; i++)
    {
        makeParent();
        sum2 = 0;
        check2 = 0;
        for(j = 0; j < edge; j++)
        {
            if(j == visited[i])continue;
            gE = graph[j    ];
            srcP = findP(gE.src);
            destP  = findP(gE.dest);
            if(srcP == destP)continue;
                parent[destP] = srcP;
                sum2 += gE.wgt;
                check2++;
            if(check2 == (node-1))
            {
                break;
            }
        }
        if(check2 == (node - 1))
        {
            sBest = min(sBest,sum2);
        }
    }
    if(sBest == INF)
    {
        serial++;
        cout<<"Case #"<<serial<<" : No second way"<<endl;

    }
    else
    {
        serial++;
        cout<<"Case #"<<serial<<" : "<<sBest<<endl;
    }
}
void findBest()
{
    int i,srcP,destP,check=0,sum=0;
    graphEdge gE;
    sort(graph,graph+edge,comp);
    makeParent();
    for(i=0; i<edge; i++)
    {
        gE = graph[i];
        srcP = findP(gE.src);
        destP  = findP(gE.dest);
        if(srcP == destP) continue;
            parent[destP] = srcP;
            sum += gE.wgt;
            check++;
            visited[check] = i;


        if(check == node-1)
        {
            break;
        }
    }
   if(check != (node-1))
    {
        serial++;
        cout<<"Case #"<<serial<<" : No way"<<endl;
        return;
    }
    else
    {
        find2ndBest(check);
    }
}
void take_input()
{
    int j,src,dest,wgt;
    cin>>node>>edge;
        for(j=0; j<edge; j++)
        {
            cin>>src>>dest>>wgt;
            graph[j].src = src;
            graph[j].dest = dest;
            graph[j].wgt =  wgt;
        }
        findBest();
}
int main()
{
    int t,i;
    cin>>t;
    for(i=1; i<=t; i++)
    {
        take_input();
    }

}
