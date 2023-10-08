class Solution
{
public:
    int mincostTickets(vector<int>& days, vector<int>& costs)
    {
        int totalDays, i,a,b,p,q,u,v;
        totalDays = days.size();
        u = totalDays + 1;
        v = 365*costs[0];
        vector<int>abc(u,v);
        abc[totalDays] = 0;
        i = totalDays -1;
        while(1)
        {
            a=i;
            b=i;
            if(i<0)
            {
                break;
            }
            while(a<totalDays && (days[a]<days[i]+7))
            {
                ++a;
            }
            while(b<totalDays && (days[b]<days[i]+30))
            {
            ++b;
            }
            p = min(abc[i+1]+costs[0],abc[a]+costs[1]);
            q = min(p,abc[b]+costs[2]);
            abc[i] = q;
            --i;
    }
    return abc[0];
    }
};
