#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class graph
{
    public:
    unordered_map<int,list<int>> gt;
    void addedge(int u, int v, bool direction)
    {
        gt[u].push_back(v);
        if(direction == 0)
        {
            gt[v].push_back(u);
        }
    }

    void printedge()
    {
        unordered_map<int,list<int>> :: iterator it;
        for(it=gt.begin(); it != gt.end(); it++)
        {
            cout<<it->first<<"-> ";
            for(auto j : it->second)
            {
                cout<<j<<"  ";
            }
            cout<<endl;
        }
    }
};

vector<int> bfs(unordered_map<int,list<int>> adj)
{
    vector<int> ans;
    unordered_map<int,bool> visited;

    if(!visited[0])
    {
        int node = visited[0];
        queue<int> q;
        q.push(node);
        visited[node] = 1;
        while(!q.empty())
        {
            int frontnode = q.front();
            cout<<"hello   "<<frontnode<<endl;
            q.pop();
            ans.push_back(frontnode);
            for(auto it:adj[frontnode])
            {
                if(!visited[it])
                {
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }
    }
    return ans;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int m;
    cin>>m;
    cout<<m<<endl;
    graph g;
    for(int i=0;i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        g.addedge(u,v,1);
    }

    g.printedge();

    vector<int> ans = bfs(g.gt);
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<"  ";
    }

    return 0;
}