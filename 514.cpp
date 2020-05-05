#include <bits/stdc++.h>
using namespace std;

// Basically counting the number of inversions. Contrary to merge sort using Fenwick Tree for the same

void solve()
{

   
   while(true){
       int n;
   cin >> n;
   if (n==0)
    break;
    while(true) {
            vector<int>arr(n);
            int f=1;
            for (int c=0;c<n;c++)
                    {cin >> arr[c];if (arr[c]==0){f=-1;cout << endl;break;}}
            if (f==-1)
                break;
            stack<int>st;
                int cur=1;
                int flag=1;
            for (int c=0;c<arr.size();c++)
                    {
                        int j=0;
                        for (int c1=cur;c1<=arr[c];c1++)
                            st.push(c1),j=1;
                        if (j==1)cur=arr[c]+1;
                        if (st.empty()||st.top()!=arr[c])
                            {flag=-1;break;}
                        else st.pop();
                        
                    }
            if (flag==1)
                cout << "Yes" << endl;
            else cout << "No" << endl;
    }
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
