#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool dfscycle(int node, unordered_map<int, list<int>> &adj, unordered_map<int,bool> &visited, unordered_map<int,bool> &dfsvisited)
{
    visited[node] = 1;
    dfsvisited[node] = 1;

    for(auto neighbour : adj[node])
    {
        if(!visited[neighbour])
        {
            bool ans = dfscycle(neighbour,adj,visited,dfsvisited);
            if(ans)
            {
                return true;
            }
        }
        else if(dfsvisited[neighbour])
        {
            return true;
        }
    }
    dfsvisited[node] = 0;
    return false;
}

int detect_DG(int n, vector<pair<int,int>> &edges)
{
    unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    unordered_map<int ,bool> visited;
    unordered_map<int, bool> dfsvisited;

    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            bool ans = dfscycle(i,adj,visited,dfsvisited);
            if(ans)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cout<<"no. of vertex"<<endl;
    cin>>n;

    int w;
    cout<<"no. of edges"<<endl;
    cin>>w;
    vector<pair<int,int>> edges;

    for(int i=0; i<w; i++)
    {
        int s,t;
        cin>>s>>t;

        pair<int,int> p1;
        p1 = make_pair(s,t);

        edges.push_back(p1);
    }

    for(int i=0; i<w; i++)
    {
        cout<<edges[i].first<<"----->"<<edges[i].second<<endl;
    }

    int ans = detect_DG(n,edges);

    cout<<ans<<endl;
    return 0;
}