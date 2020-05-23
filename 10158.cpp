#include <bits/stdc++.h>
using namespace std;
#define ll long long
int ran[10001];
int parent[10001];
int enemy[10001];
int pr(int x){if (parent[x]==x)return x; else return parent[x]=pr(parent[x]);}
int uni(int x,int y)
{
     int p1=pr(x);
     int p2=pr(y);
     if (ran[p1]<ran[p2])
        {parent[p1]=p2,ran[p2]=max(ran[p2],ran[p1]+1);return p2;}
     else 
        {parent[p2]=p1,ran[p1]=max(ran[p1],ran[p2]+1);return p1;}
    
}
void uni_f(int x,int y)
    {
        int p1=pr(x);
        int p2=pr(y);
        if (enemy[p1]==-1&&enemy[p2]==-1)
            uni(p1,p2);
        else if (enemy[p1]==-1)
            {
                int x=uni(p1,p2);
                if (x==p1)
                    enemy[p1]=enemy[p2],enemy[enemy[p2]]=p1;
            }
        else if (enemy[p2]==-1)
            {
                int x=uni(p1,p2);
                if (x==p2)
                    enemy[p2]=enemy[p1],enemy[enemy[p1]]=p2;
            }
        else
            {
                int x=uni(p1,p2);
                int y=uni(enemy[p1],enemy[p2]);
                enemy[x]=y;
                enemy[y]=x;
            }

    }
void uni_e(int x,int y)
{
    int p1=pr(x);
    int p2=pr(y);
    if (enemy[p1]==-1&&enemy[p2]==-1)
        enemy[p1]=p2,enemy[p2]=p1;
    else if (enemy[p1]==-1)
        {
            int x=uni(p1,enemy[p2]);
            enemy[x]=p2;
            enemy[p2]=x;
        }
    else if (enemy[p2]==-1)
        {
            int x=uni(p2,enemy[p1]);
            enemy[x]=p1;
            enemy[p1]=x;
        }
    else
        {
            int x=uni(p1,enemy[p2]);
            int y=uni(enemy[p1],p2);
            enemy[x]=y;
            enemy[y]=x;
        }
}
void solve()
{    
    int n;
    cin >> n;
    for (int c1=0;c1<=n;c1++)
        parent[c1]=c1,ran[c1]=0,enemy[c1]=-1;
    while(true)
    {
        int c,x,y;
        cin >> c >> x >> y;
        if (c==0)
            return;
        if (c==1)
            {
                if (enemy[pr(x)]==pr(y))
                    cout << -1 << endl;
                else uni_f(x,y);
                

            }
        else if (c==2)
            {
                if (pr(x)==pr(y))
                    cout << -1 << endl;
                else uni_e(x,y);  
            }
        else if (c==3)
            {
                cout << (pr(x)==pr(y)?1:0) << endl;
            } 
        else cout << (enemy[pr(x)]==pr(y)?1:0) << endl;
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
