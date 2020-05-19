#include <bits/stdc++.h>
using namespace std;
struct comp
{
    bool operator()(pair<int,pair<int,char>>a,pair<int,pair<int,char>>b) // distance, index
        {
            return a.second.first>b.second.first;
        }
};
int djikstra(vector<vector<pair<int,string>>>adj,int start,int end)
{
    priority_queue<pair<int,pair<int,char>>,vector<pair<int,pair<int,char>>>,comp>djk;
    unordered_map<int,unordered_map<int,unordered_map<string,int>>>done;
    djk.push(make_pair(start,make_pair(0,'A')));
    while(!djk.empty())
    {
        auto a=djk.top();
        djk.pop();
        if (a.first==end)
            return a.second.first;
        for (int c=0;c<adj[a.first].size();c++)
            {
                if (adj[a.first][c].second[0]!=a.second.second&&done[a.first][adj[a.first][c].first][adj[a.first][c].second]!=1)
                        djk.push(make_pair(adj[a.first][c].first,make_pair(a.second.first+adj[a.first][c].second.size(),adj[a.first][c].second[0]))),
                        done[a.first][adj[a.first][c].first][adj[a.first][c].second]=1;

            }
    }
    return -1;

}
void solve()
{
    while(true)
    {
        int m;
        cin >> m;
        if (m==0)
            return;
        string st,la;
        cin >> st >> la;
        vector<vector<pair<int,string>>>adj(4001);
        unordered_map<string,int>maps;
        int cur=0;
        for (int c=0;c<m;c++)
            {
                string a,b,word;
                cin >> a >> b >> word;
                if (maps.find(a)==maps.end())
                    maps[a]=cur,cur++;
                if (maps.find(b)==maps.end())
                    maps[b]=cur,cur++;
                adj[maps[a]].push_back(make_pair(maps[b],word));
                adj[maps[b]].push_back(make_pair(maps[a],word));
                
            }
            if (maps.find(st)==maps.end()||maps.find(la)==maps.end())
                {cout << "impossivel" << endl;continue;}
            int a=djikstra(adj,maps[st],maps[la]);
            if (a>=0)
                cout << a << endl;
            else cout << "impossivel" << endl;
    }
}
int main()
{
    for (int tt=1;tt<=1;tt++)
        {
            solve();
        }
}