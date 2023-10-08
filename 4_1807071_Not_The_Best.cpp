#include<bits/stdc++.h>
#define INF 100000009
#define INF2 30000000
using namespace std;
vector<int>edge[5010];
vector<int>weight[5010];
int shortest[5010];
int secondShortest[5010];
int src = 1;
int val;
int N,R;
int caseNo = 1;
class graph
{
public:

    int n;
    int m;
    graph(int n, int m)
    {
        this->n = n;
        this->m = m;
    }
    bool operator < (const graph &graph1) const{
        return  graph1.m<m;
    }
};
void add_edge(int u,int v,int w)
{
    edge[u].push_back(v);
    edge[v].push_back(u);
    weight[u].push_back(w);
    weight[v].push_back(w);
}
void init()
{
   int i;
   for(i=1;i<=N;i++)
   {
       shortest[i] = INF2;
   }
   for(i=1;i<=N;i++)
   {
       secondShortest[i] = INF2;
   }
}
void dijkstra()
{
    int u,v,w,i,p,si;
    priority_queue<graph>Q;
    Q.push(graph(src, 0));
    init();
    shortest[src] = 0;
    while(1)
    {
        if(Q.empty()){
            break;
        }
        graph fr = Q.top();
        Q.pop();
        u=fr.n;
        si=edge[u].size();
        for(i=0;i<=(si-1);i++){
            v=edge[u][i];
            w=weight[u][i];
            if(shortest[u]+w<shortest[v]){
                p=shortest[v];
                shortest[v]=shortest[u]+w;
                secondShortest[v]=min(p, min(secondShortest[v], min(secondShortest[u]+w, shortest[u]+3*w)));
                Q.push(graph(v, shortest[v]+secondShortest[v]));
            }
            else if(shortest[u]+w<secondShortest[v] && (shortest[u]+w)>shortest[v]){
                secondShortest[v]=shortest[u]+w;
            }
            else{
                secondShortest[v]=min(secondShortest[v], min(secondShortest[u]+w, shortest[u]+3*w));
            }
        }
    }


}
void spFunc()
{
    int i;
    val =  INF;
    int r = (edge[1].size())-1;
    for(i=0; i<=r; i++)
    {
        val = min(val,2*(weight[1][i]));
    }
}
void clearV()
{
    int i;
    for(i=0;i<=5010;i++){
        edge[i].clear();
        weight[i].clear();
    }
}
void print_output()
{

        val=shortest[N]+val;
        cout<<"Case "<<caseNo++<<": "<<min(val, secondShortest[N])<<endl;
}
void take_input()
{
    int i,u,v,w;
    cin>>N>>R;
    for(i=1; i<=R; i++)
    {
        cin>>u>>v>>w;
        add_edge(u,v,w);
    }
}
int main()
{
    int T,i;
    cin>>T;
    for(i=1; i<=T; i++)
    {
        take_input();
        spFunc();
        dijkstra();
        print_output();
        clearV();
    }
}

