#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Graph
{
    public:
    unordered_map<int,list<pair<int,int>>> adj;

    void addedge(int u, int v, int weight)
    {
        pair<int,int> p = make_pair(v,weight);
        cout<<"call"<<endl;
        cout<<p.first<<"  "<<p.second<<endl;
        adj[u].push_back(p);
    }

    void print()
    {
        for(int i=0; i<adj.size(); i++)
        {
            cout<<i<<"  ";
            for(auto j: adj[i])
            {
                cout<<"("<<j.first<<", "<<j.second<<") ";
            }
            cout<<endl;
        }
    }

    void dfs(int node, unordered_map<int,bool> &visited, stack<int> &s)
    {
        visited[node] = true;

        for(auto neighbour: adj[node])
        {
            if(!visited[neighbour.first])
            {
                dfs(neighbour.first,visited,s);
            }
        }

        s.push(node);

    }
    
    void get_shortest_path(int src, vector<int> &dist, stack<int> &s)
    {
        dist[src] = 0;

        while(!s.empty())
        {
            int top = s.top();
            s.pop();

            if(dist[top] != INT_MAX)
            {
                for(auto i:adj[top])
                {
                    if(dist[top] + i.second < dist[i.first])
                    {
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
        }
    }
};

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    Graph g;

    int e;
    cin>>e;
    for(int i=0; i<e; i++)
    {
        int u,v,weight;
        cin>>u>>v>>weight;
        g.addedge(u,v,weight);
    }
    g.print();
    int n = 6;
    unordered_map<int,bool> visited;
    stack<int> s;
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            g.dfs(i,visited,s);
        }
    }

    int src = 1;
    vector<int> dist(n);
    for(int i=0; i<n; i++)
    {
        dist[i] = INT_MAX;
    }

    g.get_shortest_path(src,dist,s);

    for(int i=0; i<dist.size(); i++)
    {
        cout<<dist[i]<<"  ";
    }
    cout<<endl;
}