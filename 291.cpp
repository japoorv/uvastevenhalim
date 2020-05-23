#include <bits/stdc++.h>
using namespace std;
#define ll long long
unordered_map<int,unordered_map<int,int>>done;
vector<int>cur;
vector<vector<int>>ans;
bool check(vector<vector<int>>&adj)
{
    for (int c=0;c<adj.size();c++)
        for (int c1=0;c1<adj[c].size();c1++)
            if (done[min(c,adj[c][c1])][max(c,adj[c][c1])]==0)
                return 0;
    return 1;
}
void dfs(int node,vector<vector<int>>&adj)
{
    cur.push_back(node+1);
    int flag=0;
    for (int c=0;c<adj[node].size();c++)
        {
            if (done[min(node,adj[node][c])][max(node,adj[node][c])]==0)
                {
                    done[min(node,adj[node][c])][max(node,adj[node][c])]=1;
                    dfs(adj[node][c],adj);
                    done[min(node,adj[node][c])][max(node,adj[node][c])]=0;
                    flag++;
                }
        }
    if (flag==0&&check(adj))
        ans.push_back(cur);
    cur.pop_back();
    return ;

    
}
bool comp(vector<int>a,vector<int>b)
{
    int c=0;
    for (;c<a.size()&&a[c]==b[c];c++);
    return a[c]<b[c];
}
void solve()
{    
   vector<vector<int>> adj={
       {1,2,4},
       {0,2,4},
       {0,1,3,4},
       {2,4},
       {0,1,2,3}
   };
   dfs(0,adj);
   sort(ans.begin(),ans.end(),comp);
   for (int c=0;c<ans.size();c++)
    {
        for (int c1=0;c1<ans[c].size();c1++)
            cout << ans[c][c1];
        cout << endl;
    }
    
}

int main ()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
      
     int t;
     //cin >> t;
     t=1;
     for (int tt=1;tt<=t;tt++)
     {
         solve();

     }

    return 0;
     
     
     
     
 }
