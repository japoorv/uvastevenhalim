//Arctic Network : Kruskal's with twist
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int ran[501],parent[501];
int pr(int x){if (parent[x]==x)return x;else return parent[x]=pr(parent[x]);}
void uni(int x,int y){int p1=pr(x);int p2=pr(y);if (p1==p2)return;if (ran[p1]<ran[p2])parent[p1]=p2,ran[p2]=max(ran[p2],ran[p1]+1); else parent[p2]=p1,ran[p1]=max(ran[p1],ran[p2]+1);return;}
struct edge{
    int u,v;
    double distance;
    edge(pair<int,int>a,pair<int,int>b,int u,int v)
    {
        this->u=u;
        this->v=v;
        this->distance=sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
        return ;
    }   
};
bool comp(edge a,edge b)
{
    return a.distance<b.distance;
}
void solve()
{
    int s,p;
    cin >> s >> p;
    s--;
    vector<pair<int,int>>arr;
    for (int c=0;c<=p;c++)
        parent[c]=c,ran[c]=0;
    for (int c=0;c<p;c++)
        {int a,b;cin >> a >> b;arr.push_back(make_pair(a,b));}
    vector<edge>edges;
    for (int c=0;c<arr.size();c++)
        {
            for (int c1=c+1;c1<arr.size();c1++)
                {
                    edge*a= new edge(arr[c],arr[c1],c,c1);
                    edges.push_back(*a);
                }
        }  
    
    sort(edges.begin(),edges.end(),comp);
    vector<edge>sol;
    double d_max=0;
    for (int c=0;c<edges.size();c++)
        {
            if (pr(edges[c].u)!=pr(edges[c].v))
                sol.push_back(edges[c]),uni(edges[c].u,edges[c].v);
        }
    sort(sol.begin(),sol.end(),comp);
    cout << setprecision(2) << fixed << (sol.size()-1>=s?sol[sol.size()-s-1].distance:0) << endl;
}
int main ()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
      
     int t;
     cin >> t;
     
     for (int tt=1;tt<=t;tt++)
     {
         solve();

     }

    return 0;
     
     
     
     
 }
