#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> Topological_sort(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int>> adj;
    for(int i=0; i<e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    vector<int> indegree(v);
    for(auto i:adj)
    {
        for(auto j: i.second)
        {
            indegree[j]++;
        }
    }

    queue<int> q;
    for(int i=0; i<v; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> ans;
    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        ans.push_back(front);
        for(auto neighbour : adj[front])
        {
            indegree[neighbour]--;
            if(indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }

    return ans;
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
        for(int j=0; j<=1; j++)
        {
            cout<<edges[i][j]<<"  ";
        }
        cout<<endl;
    }

    vector<int> ans = Topological_sort(edges,v,e);
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<"  ";
    }

    return 0;
}