#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void dfs(int node, int parent, int &timer, vector<int> &low, vector<int> &tin, vector<vector<int>> &result, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj)
{
    vis[node] = true;
    tin[node] = low[node] = timer++;
    cout<<"node--->"<<node<<" timer--->"<<timer<<" tin[node]--->"<<tin[node]<<" low[node]--->"<<low[node]<<endl;
    for(auto nbr : adj[node])
    {
        if(nbr == parent)
        {
            continue;
        }

        if(!vis[nbr])
        {
            dfs(nbr , node, timer, low, tin, result, vis, adj);
            low[node] = min(low[node] , low[nbr]);
            if(low[nbr] > tin[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else
        {
            low[node] = min(low[node] , tin[nbr]);
        }
    }
}

vector<vector<int>> Bridges(vector<vector<int>> &edges, int v)
{
    unordered_map<int , list<int>> adj;
    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> tin(v);
    vector<int> low(v);
    int parent  = -1;
    unordered_map<int , bool> vis;
    vector<vector<int>> result;

    for(int i=0; i<v; i++)
    {
        tin[i] = -1;
        low[i] = -1;
    }

    for(int i=0; i<v; i++)
    {
        if(!vis[i])
        {
            dfs(i, parent, timer, low, tin, result, vis, adj);
        }
    }

    return result;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    vector<vector<int>> edges;
    int v,e;
    cin>>v>>e;
    for(int i=0; i<e; i++)
    {
        vector<int> temp;
        for(int j=0; j<=1; j++)
        {
            int t;
            cin>>t;
            temp.push_back(t);
        }
        edges.push_back(temp);
    }

    for(int i=0; i<e; i++)
    {
        vector<int> temp;
        for(int j=0; j<=1; j++)
        {
            cout<<edges[i][j]<<" ";
        }
        cout<<endl;
    }

    vector<vector<int>> ans = Bridges(edges,v);
    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<"  ";
        }
        cout<<endl;
    }

    return 0;
}