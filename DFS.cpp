#include<iostream>
#include<bits/stdc++.h>

using namespace std;
void dfs(int node, unordered_map<int,list<int>> &adj, unordered_map<int,bool> &visited, vector<int> &component)
{
    component.push_back(node);
    visited[node] = true;

    for(auto i:adj[node])
    {
        if(!visited[i])
        {
            dfs(i,adj,visited,component);
        }
    }
}

vector<vector<int>> dfsgraph(int V,vector<vector<int>> edges)
{
    unordered_map<int,list<int>> adj;

    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int,bool> visited;

    for(int i=0; i<V; i++)
    {
        if(!visited[i])
        {
            vector<int> component;
            dfs(i,adj,visited,component);
            ans.push_back(component);
        }
    }
    return ans;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int V;
    cin>>V;
    cout<<V;
    cout<<endl;
    vector<vector<int>> edges;
    for(int i=0; i<V; i++)
    {
        vector<int> temp;
        for(int j=0; j<=1; j++)
        {
            int u;
            cin>>u;
            temp.push_back(u);
        }
        edges.push_back(temp);
    }
    for(int i=0; i<edges.size(); i++)
    {
        for(int j=0; j<edges[i].size(); j++)
        {
            cout<<edges[i][j]<<"  ";
        }
        cout<<endl;
    }

    vector<vector<int>> ans = dfsgraph(V,edges);
    cout<<ans.size()<<endl;
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