#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void dfs(int node, unordered_map<int,bool> &vis, unordered_map<int, list<int>> &adj, stack<int> &s)
{
    vis[node] = true;
    for(auto nbr : adj[node] )
    {
        if(!vis[nbr])
        {
            dfs(nbr,vis,adj,s);
        }
    }

    s.push(node);
}

void revdfs(int node, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &transpose)
{
    vis[node] = true;

    for(auto nbr : transpose[node])
    {
        if(!vis[nbr])
        {
            revdfs(nbr, vis, transpose);
        }
    }
}

int cscc(int v, vector<vector<int>> edges)
{
    unordered_map<int, list<int>> adj;
    for(int j=0; j<edges.size(); j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];

        adj[u].push_back(v);
    }

    stack<int> s;
    unordered_map<int ,bool> vis;
    for(int i=0; i<v; i++)
    {
        if(!vis[i])
        {
            dfs(i, vis, adj, s);
        }
    }

    unordered_map<int, list<int>> transpose;
    for(int i=0; i<v; i++)
    {
        vis[i] = 0;
        for(auto nbr : adj[i])
        {
            transpose[nbr].push_back(i);
        }
    }

    int count = 0; 
    while(!s.empty())
    {
        int top = s.top();
        s.pop();
        if(!vis[top])
        {
            count++;
            revdfs(top, vis, transpose);
        }
    }

    return count;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int v,e;
    cin>>v>>e;

    vector<vector<int>> edges;
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

    int ans = cscc(v,edges);
    cout<<ans<<endl;
    return 0;
}