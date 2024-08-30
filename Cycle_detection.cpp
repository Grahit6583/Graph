#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool cyclebfs(int src,unordered_map<int,list<int>> adj,unordered_map<int, bool> visited)
{
    unordered_map<int ,int> parent;
    parent[src]  = -1;
    visited[src] = 1;
    queue<int> q;
    q.push(src);

    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        for(auto neighbour : adj[front])
        {
            if(visited[neighbour] == true && neighbour != parent[front])
            {
                return true;
            }
            else if(!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = front;
            }
        }
    }
    return false;
}

string cycledetect(vector<vector<int>> &edges, int n ,int m)
{
    unordered_map<int,list<int>> adj;

    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;

    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            bool ans = cyclebfs(i,adj,visited);
            if(ans == true)
            {
                return "Yes";
            }
        }
    }
    return "No";
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<vector<int>> edges;
    //n is no. of vertices;
    int n,m;
    cin>>n>>m;

    for(int i=0; i<m; i++)
    {
        vector<int> temp;
        for(int j=0; j<=1; j++)
        {
            int t ;
            cin>>t;
            temp.push_back(t);
        }

        edges.push_back(temp);
    }

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<=1; j++)
        {
            cout<<edges[i][j]<<"  ";
        }
        cout<<endl;
    }

    string ans  = cycledetect(edges,n,m);
    cout<<ans<<endl;

    return 0;
}