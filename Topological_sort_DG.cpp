#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void toposort(int node, vector<bool> &visited, stack<int> &s, unordered_map<int,list<int>> &adj)
{
    visited[node] = 1;
    for(auto neighbour : adj[node])
    {
        if(!visited[neighbour])
        {
            toposort(neighbour,visited,s,adj);
        }
    }

    s.push(node);
}

vector<int> topological_sort(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int,list<int>> adj;
    for(int i=0; i<e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    vector<bool> visited(v);
    stack<int> s;
    for(int i=0; i<v; i++)
    {
        if(!visited[i])
        {
            toposort(i,visited,s,adj);
        }
    }

    vector<int> ans;
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
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

    for(int i=0; i<e; i++)
    {
        cout<<edges[i][0]<<"--->"<<edges[i][1]<<endl;
    }

    vector<int> ans = topological_sort(edges,v,e);
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<"  ";
    }

    return 0;
}