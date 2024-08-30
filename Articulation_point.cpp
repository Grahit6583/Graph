#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void dfs(int node, int parent, int &timer, vector<int> &tin, vector<int> &low, unordered_map<int , bool> &vis, unordered_map<int,list<int>> &adj, vector<int> &ap)
{
    vis[node] = true;
    low[node] = tin[node] = timer++;

    int child = 0;
    for(auto nbr : adj[node])
    {
        if(nbr == parent)
        {
            continue;
        }

        if(!vis[nbr])
        {
            dfs(nbr, node, timer, tin, low, vis, adj, ap);
            low[node] = min(low[node], low[nbr]);
            if(low[nbr] >= tin[node] && parent != -1)
            {
                ap[node]  = 1;
            }
            child++;
        }
        else
        {
            low[node] = min(low[node], tin[nbr]);
        }
    }

    if(parent == -1 && child > 1)
    {
        ap[node] = 1;
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int v,e;
    cin>>v>>e;
    // vector<vector<int>> edges;
    
    // for(int i=0; i<e; i++)
    // {
    //     vector<int> temp;
    //     for(int j=0; j<=1; j++)
    //     {
    //         int t;
    //         cin>>t;
    //         temp.push_back(t);
    //     }
    //     edges.push_back(temp);
    // }

    unordered_map<int ,list<int>> adj;
    for(int i=0; i<e; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> tin(v);
    vector<int> low(v);
    int parent = -1;
    unordered_map<int , bool> vis;
    vector<int> ap(v,0);

    for(int i=0; i<v; i++)
    {
        tin[i] = -1;
        low[i] = -1;
    }

    for(int i=0; i<v; i++)
    {
        if(!vis[i])
        {
            dfs(i,parent,timer,tin,low,vis,adj,ap);
        }
    }

    for(int i=0; i<ap.size(); i++)
    {
        if(ap[i] != 0)
        {
            cout<<i<<"  ";
        }
    }
}