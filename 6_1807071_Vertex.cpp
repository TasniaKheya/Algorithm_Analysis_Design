#include<bits/stdc++.h>
using namespace std;
#define INF 100000
vector< vector<int> > ara;
int ara2[101];
int n;
void initArr()
{
  int i;
  for(i=0;i<=n;i++){
    ara2[i] = 0;
  }
}
void add_edge(int i,int j)
{
    ara[i].push_back(j);
}

void find_output()
{
    int cnt=0,i;
    for(i=0; i<n; i++)
    {
        if(!ara2[i])cnt++;

    }
    cout<<cnt;
    for(i=0; i<n; i++)
    {
        if(!ara2[i])
              cout<<" "<<i+1;
    }
    cout<<endl;
}

void bfs(int r)
{
    initArr();
    int i,fnt,p;
    queue<int>q;
    q.push(r);
    while(!q.empty())
    {
        fnt = q.front();
        q.pop();
        for(i=0; i<ara[fnt].size(); i++)
        {
            p = ara[fnt][i];
            if(ara2[p])continue;
                ara2[p] =1;
                q.push(p);
        }
    }
    find_output();
    return;
}
void init()
{
    ara.clear();
    ara.resize(n);
}
void take_input2()
{
        int cnt,p,k;
        cin>>cnt;
        for(p=1; p<=cnt; p++)
        {
            cin>>k;
            bfs(k-1);
        }
}
void take_input()
{
    int i,j,k,a;
    for(a=1;;)
    {
        cin>>n;
        if(n == 0)break;
        init();
        for(a=1;;)
        {
            cin>>i;
            if(i == 0)break;
            for(a=1;;)
            {
                cin>>j;
                if(j == 0)break;
                 add_edge(i-1,j-1);
            }
        }
        take_input2();

    }
}

int main()
{
    take_input();
}

