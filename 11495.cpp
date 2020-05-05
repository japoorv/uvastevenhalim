#include <bits/stdc++.h>
using namespace std;

// Basically counting the number of inversions. Contrary to merge sort using Fenwick Tree for the same
void update(long long int *bit,int ind,int val,int n)
{
    while (ind<=n)
        {
            bit[ind]+=val;
            ind+=(ind&(-ind));
        }
    return ;
}
void update_range(long long int *bit,int l,int r,int val,int n)
{
    if (l>r)
        return ;
        update(bit,l,val,n);
        update(bit,r+1,-val,n);
        return;
}
long long int query(long long int *bit,int ind)
{
    int total=0;
    while(ind>0)
        total+=bit[ind],ind-=(ind&(-ind));
    return total;
}
void solve()
{
    while(true)
        {
            int n;
            cin >> n;
            if (n==0)
                return ;
            vector<pair<int,int>>arr(n);
            for (int c=0;c<n;c++)
                {pair<int,int>a;cin >> a.first;a.second=c;arr[c]=a;}
            sort(arr.begin(),arr.end());
            long long int* bit=new long long int[500000];
            memset(bit,0,sizeof(bit));
            int cur=0;
            long long int total=0;
            for (int c=0;c<n;c++)
                {
                total+=query(bit,arr[c].second+1)+arr[c].second-c;
                update_range(bit,1,arr[c].second,1,n);
                }
                cout << (total%2==1?"Marcelo":"Carlos") << endl;
        }
}



int main ()
{
      
     int t;
     //cin >> t;
     t=1;
     for (int tt=1;tt<=t;tt++)
     {
         solve();

     }

    return 0;
     
     
     
     
 }
