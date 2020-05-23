//Segment Trees
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int seg[4*100001];
vector<int>arr;
int bin_srch(int i,int j,int val)
{
    int x=(val==1?arr[i]:arr[j]);
    int i1=i;
    int j1=j;
    while(j1-i1>1)
    {
        int mid=(i1+j1)/2;
        if (arr[mid]==x)
            {
                if (val%2==1)
                    i1=mid;
                else j1=mid;
            }
        else {if (val%2==1)j1=mid; else i1=mid;}
    }
    if (val%2==1)
    {   if (arr[j1]==x)
            return j1;
        else return i1;
    }
    else 
    {
        if (arr[i1]==x)
            return i1;
        else return j1;
    }
}
void build_seg(int node,int i,int j)
{
    if (i>j)
        return;
    if (i==j)
        {seg[node]=1;return;}
    build_seg(node*2,i,(i+j)/2);
    build_seg(node*2+1,(i+j)/2+1,j);
    int k2=bin_srch((i+j)/2+1,j,1);
    int k1=bin_srch(i,(i+j)/2,0);
    seg[node]=max(seg[node*2+1],max(seg[node*2],(k2-k1+1)*(arr[(i+j)/2]==arr[(i+j)/2+1]?1:0)));
    return;
}
int query(int node,int l,int r,int q_l,int q_r)
{
    if (l>r||r<q_l||l>q_r)
        return 0;
    if (l==r)
        return 1;
    if (l>=q_l&&r<=q_r)
        return seg[node];
    int x=query(node*2,l,(l+r)/2,q_l,q_r);
    int y=query(node*2+1,(l+r)/2+1,r,q_l,q_r);
    int u=max((l+r)/2+1,q_l);
    int v=min(r,q_r);
    int k2=-1,k1=-1;
    if ((l+r)/2+1>=q_l&&(l+r)/2+1<=q_r)
       k2=bin_srch((l+r)/2+1,min(r,q_r),1);
    if ((l+r)/2>=q_l&&(l+r)/2<=q_r)
        k1=bin_srch(max(l,q_l),(l+r)/2,0);
    return max(max(x,y),(k2-k1+1)*(k2!=-1&&k1!=-1&&arr[(l+r)/2+1]==arr[(l+r)/2]?1:0));
}
void solve()
{
    while(true)
    {
        int n,q;
        cin >> n;
        if (n==0)
            return;
        cin >> q;
        arr.resize(n);
        for (int c=0;c<n;c++)
            cin >> arr[c];
        build_seg(1,0,n-1);
        for (int c=0;c<q;c++)
            {
                int a,b;
                cin >> a >> b;
                cout << query(1,0,n-1,a-1,b-1) << endl;
            }
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
