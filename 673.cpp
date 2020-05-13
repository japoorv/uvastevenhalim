#include <bits/stdc++.h>
using namespace std;

// Basically counting the number of inversions. Contrary to merge sort using Fenwick Tree for the same

void solve()
{
    string a;
    getline(cin,a);
    stack<char>st;
    int flag=1;
    for (int c=0;c<a.size();c++)
        {
            if (a[c]=='['||a[c]=='(')
                st.push(a[c]);
            else if (a[c]==']')
                {
                    if (st.empty()||st.top()!='[')
                        {flag=-1;break;}
                    else st.pop();
                } 
            else if (a[c]==')')
                {
                    if (st.empty()||st.top()!='(')
                        {flag=-1;break;}
                    st.pop();
                }

        }
        if (flag==1&&st.size()==0)
            cout << "Yes" << endl;
        else cout << "No" << endl;
}



int main ()
{
      
     int t;
     cin >> t;
     cin.ignore();
     for (int tt=1;tt<=t;tt++)
     {
         solve();

     }

    return 0;
     
     
     
     
 }
