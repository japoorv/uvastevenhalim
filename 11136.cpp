#include <bits/stdc++.h>
using namespace std;
#define ll long long //important for working of maps
void solve()
{
    while(true)
        {
            int n;
            cin >> n;
            if (n==0)
                return ;
            map<int,int>arr;
            ll total=0;
            for (int c=0;c<n;c++)
                {
                    int k;
                    cin >> k;
                    for (int c1=0;c1<k;c1++)
                        {int a;cin >> a;arr[a]++;}
                    total+=arr.rbegin()->first-arr.begin()->first;
                    if (arr.rbegin()->second==1)
                        {auto it=arr.end();it--;arr.erase(it);}
                    else arr.rbegin()->second--;
                    if (!arr.empty()&&arr.begin()->second==1)
                        arr.erase(arr.begin());
                    else arr.begin()->second--;
                    
                }
            
                cout << total << endl;
        }
        return ;
}
int main()
{
    for (int tt=1;tt<=1;tt++)
    {
        solve();
    }
}
