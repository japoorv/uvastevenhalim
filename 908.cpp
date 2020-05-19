#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int>ran;
vector<int>parent;
struct edge
{
    int cost;
    int u,v;
};
bool comp(edge a,edge b)
{
    return a.cost<b.cost;
}
int pr(int node)
{
    if (parent[node]==node)
        return node;
    else {int c=pr(parent[node]);parent[node]=c;return c;}
}
void uni(int a,int b)
{
    int p_a=pr(a);
    int p_b=pr(b);
    if (p_a==p_b)
        return;
    else if (ran[p_a]<=ran[p_b])
        {
            parent[p_a]=p_b;
            ran[p_b]=max(1+ran[p_a],ran[p_b]);
        }
    else 
        {parent[p_b]=p_a;ran[p_a]=max(ran[p_a],1+ran[p_b]);}
    return ;
}
bool check(edge a)
{
    if (pr(a.u)==pr(a.v))
        return false;
    return true;
}
void solve()
{
    int n;
    int t=0;
    while(cin>>n)
    {
        if (t!=0)
            cout << endl;
            t++;
        parent.resize(n+1);
        ran.resize(n+1,1);
        for (int c=1;c<=n;c++)
            parent[c]=c;
        ll total=0;
        for (int c=0;c<n-1;c++)
            {
                int a,b,cost;
                cin >> a >> b >> cost;
                total+=cost;
            }
        vector<edge>edges;
        int k;
        cin >> k;
        for (int c=0;c<k;c++)
            {
                edge a;
                cin >> a.u >> a.v >> a.cost;
                edges.push_back(a);
            }
        int m;
        cin >> m;
        for (int c=0;c<m;c++)
            {
                edge a;
                cin >> a.u >> a.v >> a.cost;
                edges.push_back(a);
            }
        sort(edges.begin(),edges.end(),comp);
        ll total_new=0;
        for (int c=0;c<edges.size();c++)
            {
                if (check(edges[c]))
                    total_new+=edges[c].cost,uni(edges[c].u,edges[c].v);
            }
        cout << total << endl << min(total,total_new) << endl ;
    }
        
}
int main()
{
    for (int tt=1;tt<=1;tt++)
        {
            solve();
        }
}