#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<pair<pair<int,int>, int>> Prims_Mst(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0; i<g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);

    for(int i=0; i<=n; i++)
    {
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    key[1] = 0;
    parent[1] = -1;

    for(int i=1; i<n; i++)
    {
        int mini = INT_MAX;
        int u;

        for(int v=1; v<=n; v++)
        {
            if(mst[v] == false && key[v] < mini)
            {
                u=v;
                mini = key[v];
            }
        }
        mst[u] = true;

        for(auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if(mst[v] == false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int,int>,int>> result;
    for(int i=2; i<=n; i++)
    {
        result.push_back({{parent[i],i},key[i]});
    }

    return result;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;

    vector<pair<pair<int,int>,int>> g;
    for(int i=0; i<m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g.push_back({{u,v},w});        
    }

    for(int i=0; i<m; i++)
    {
        cout<<g[i].first.first<<"  "<<g[i].first.second<<"  "<<g[i].second<<endl;
    }

    cout<<"hello"<<endl;
    vector<pair<pair<int,int>,int>> ans = Prims_Mst(n,m,g);

    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i].first.first<<"  "<<ans[i].first.second<<"  "<<ans[i].second<<endl;
    }

    return 0;
}