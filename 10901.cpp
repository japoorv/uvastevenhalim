#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,t,m;
    cin >> n >> t >> m;
    queue<pair<int,int>>left;
    queue<pair<int,int>>right;
    for (int c=0;c<m;c++)
        {
            int a;
            string bank;
            cin >> a >> bank;
            if (bank=="left")
                left.push(make_pair(a,c));
            else 
                right.push(make_pair(a,c));

        }
    vector<int>res(m);

    int cur_t=0;
    int which=0;
    while(!left.empty()||!right.empty())
        {
            int howm=0;
            
            if (which%2==0)
                {
                    int flag=0;
                    while(!left.empty()&&left.front().first<=cur_t&&howm<n)
                        {
                            res[left.front().second]=cur_t+t;
                            left.pop();
                            flag=1;
                            which=1;
                            howm++;
                            
                        }
                        if (flag==1)
                            {cur_t+=t;continue;}


                }
            else {
                   int flag=0;
                    while(!right.empty()&&right.front().first<=cur_t&&howm<n)
                        {
                            res[right.front().second]=cur_t+t;
                            right.pop();
                            flag=1;
                            which=0;
                            howm++;
                            
                        }
                        if (flag==1)
                            {cur_t+=t;continue;}

            }
            
            int min_1=(left.empty()?1000000001:left.front().first);
            int min_2=(right.empty()?1000000001:right.front().first);
            if (min_1<=min_2)
                {
                    if (which%2==0)
                        cur_t=min_1;
                    else {if (cur_t>=min_1)cur_t+=t,which=0;else cur_t=min_1+t,which=0;}
                }
            else 
                {
                    if (which%2==1)
                        cur_t=min_2;
                    else {if (cur_t>=min_2)cur_t+=t,which=1; else cur_t=min_2+t,which=1;}
                }


        }
        for (int c=0;c<res.size();c++)
            cout << res[c] << endl;
        
        
}



int main ()
{
      
     int t;
     cin >> t;
     //t=1;
     for (int tt=1;tt<=t;tt++)
     {
         solve();
         if (tt!=t)
            cout << endl;

     }

    return 0;
     
     
     
     
 }
