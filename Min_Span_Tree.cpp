#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

class Disjoint_Set
{
    vector<int> rank,parent;
    public:
    Disjoint_Set(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);

        for(int i=0; i<=n; i++)
        {
            parent[i] = i;
        }
    }

    int Find_par(int node)
    {
        if(node == parent[node])
        {
            return node;
        }
        return parent[node] = Find_par(parent[node]);
    }

    void UnionByRank(int u, int v)
    {
        int ul_u = Find_par(u);
        int ul_v = Find_par(v);
        if(ul_u == ul_v)
        {
            return;
        }
        else if(rank[ul_u] < rank[ul_v])
        {
            parent[ul_u] = ul_v;
        }
        else if(rank[ul_v] < rank[ul_u])
        {
            parent[ul_v] = ul_u;
        }
        else
        {
            parent[ul_v] = ul_u;
            rank[ul_u]++;
        }
    }


    int MinSpanTree(vector<vector<int>> &edges, int n)
    {
        // Sort by its weight
        sort(edges.begin(), edges.end(), cmp);

        int MinWt = 0;
        for(int i =0; i<n; i++)
        {
            int u = Find_par(edges[i][0]);
            int v = Find_par(edges[i][1]);
            int wt = edges[i][2];
            
            if(u != v)
            {
                cout<<u<<"----->"<<v<<"----->"<<wt<<endl;
                MinWt += wt;
                UnionByRank(u,v);
            }
        }
        return MinWt;
    }
};

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int vertex,edge;
    cin>>vertex>>edge;
    Disjoint_Set ds(vertex);

    vector<vector<int>> edges;
    for(int i=0; i<edge; i++)
    {
        vector<int> temp;
        for(int j=0; j<=2; j++)
        {
            int k;
            cin>>k;
            temp.push_back(k);
        }
        edges.push_back(temp);
    }

    for(int i=0; i<edges.size(); i++)
    {
        cout<<edges[i][0]<<"  "<<edges[i][1]<<"  "<<edges[i][2]<<endl;
    }
    cout<<endl;
    int ans = ds.MinSpanTree(edges,vertex);
    cout<<ans<<endl;
    return 0;
}