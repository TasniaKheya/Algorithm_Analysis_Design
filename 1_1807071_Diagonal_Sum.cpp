#include<bits/stdc++.h>
#define N 210
#define INF 0x3f3f3f3f
using namespace std;
class edge
{
public:
    int to, cap, id, next;
} g[N*N*2];
int cnt, nv, src[N], level[N], gap[N], cur[N], pre[N];
int ans[N*N];
int cas;
void connectEdge(int v, int u, int cap)
{
    g[cnt].to = u;
    g[cnt].cap = cap;
    g[cnt].next = src[v];
    src[v] = cnt++;
    g[cnt].to = v;
    g[cnt].cap = 0;
    g[cnt].next = src[u];
    src[u] = cnt++;
}
int find_output(int s, int t)
{
    memset(level, 0, sizeof level);
    memset(gap, 0, sizeof gap);
    memcpy(cur, src, sizeof src);
    gap[0] = nv;
    int v = pre[s] = s, flow = 0, aug = INF;
    while(level[s] < nv)
    {
        bool flag = false;
        for(int &i = cur[v]; i != -1; i = g[i].next)
        {
            int u = g[i].to;
            if(g[i].cap > 0 && level[v] == level[u] + 1)
            {
                flag = true;
                pre[u] = v;
                v = u;
                aug = min(aug, g[i].cap);
                if(v == t)
                {
                    flow += aug;
                    while(v != s)
                    {
                        v = pre[v];
                        g[cur[v]].cap -= aug;
                        g[cur[v]^1].cap += aug;
                    }
                    aug = INF;
                }
                break;
            }
        }
        if(flag) continue;
        int minlevel = nv;
        for(int i = src[v]; i != -1; i = g[i].next)
        {
            int u = g[i].to;
            if(g[i].cap > 0 && minlevel > level[u])
                minlevel = level[u], cur[v] = i;
        }
        if(--gap[level[v]] == 0) break;
        level[v] = minlevel + 1;
        gap[level[v]]++;
        v = pre[v];
    }
    return flow;
}
int main()
{
    int t, n, m, a;
    scanf("%d", &t);
    while(t--)
    {
        cnt = 0;
        memset(src, -1, sizeof src);
        scanf("%d%d", &n, &m);
        int ss = 0, tt = 2 * (n+m-1) + 1;
        for(int i = 1; i <= n + m - 1; i++)
        {
            scanf("%d", &a);
            a -= min(n, i) - max(0, i-m);
            connectEdge(ss, i, a);
        }
        for(int i = 1; i <= n + m - 1; i++)
        {
            scanf("%d", &a);
            a -= min(n, i) - max(0, i-m);
            connectEdge(i + n+m-1, tt, a);
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                connectEdge(i+j-1, m+i-j + n+m-1, 99), ans[(i-1)*m+j] = cnt - 1;
            }
        }
        nv = tt + 1;
        find_output(ss, tt);
        printf("Case %d:\n", ++cas);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                printf("%d%c", g[ans[(i-1)*m+j]].cap + 1, j == m ? '\n' : ' ');
            }
        }
    }
    return 0;
}
