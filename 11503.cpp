#include <bits/stdc++.h>
using namespace std;
#define ll long long
int parent[2*100001],ran[2*100001],howm[2*100001];
int pr(int x){if (parent[x]==x)return x; else {int a=pr(parent[x]);parent[x]=a;return a;}}
void uni(int x,int y){int p1=pr(x);int p2=pr(y);if (p1==p2)return; else if (ran[p1]<ran[p2])parent[p1]=p2,ran[p2]=max(ran[p2],ran[p1]+1),howm[p2]+=howm[p1]; else parent[p2]=p1,ran[p1]=max(ran[p1],ran[p2]+1),howm[p1]+=howm[p2];}
void solve()
{    
    
   int f;
   cin >> f;
   for (int c=0;c<2*f;c++)
        parent[c]=c,ran[c]=0,howm[c]=1; 
   unordered_map<string,int>name;
   vector<vector<int>>adj;
   int cur=1; 
   for (int c=0;c<f;c++)
   {
       string a,b;
       cin >> a >> b;
       if (name[a]==0)
            name[a]=cur,cur++;
       if (name[b]==0)
            name[b]=cur,cur++;
       uni(name[a],name[b]);
       cout << howm[pr(name[a])] << endl;  
   }

   return ;
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
