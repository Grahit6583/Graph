#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> Bellmon_algo(int n, int m, vector<vector<int>> edges, int src)
{
    vector<int> dist(n+1, 1e9);
    dist[src] = 0;

    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<edges.size(); j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            if(dist[u] != 1e9 && ((dist[u] + wt) < dist[v]))
            {
                dist[v] = dist[u] + wt;
            }
        }
    }
    dist.erase(dist.begin());
    return dist;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m,src;
    cin>>n>>m>>src;

    vector<vector<int>> edges;

    for(int i=0; i<n; i++)
    {
        vector<int> temp;
        for(int j=0; j<=2; j++)
        {
            int t;
            cin>>t;
            temp.push_back(t);
        }
        edges.push_back(temp);
    }

    for(int i=0; i<edges.size(); i++)
    {
        cout<<edges[i][0]<<"  "<<edges[i][1]<<"  "<<edges[i][2]<<endl;
    }
    vector<int> ans = Bellmon_algo(n,m,edges,src);

    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<"  ";
    }

    return 0;
}