#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> Dijkstra(vector<vector<int>> &vec, int edges,int vertices, int source)
{
    // cout<<edges<<"  "<<vertices<<"  "<<source<<endl;
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0; i<edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

        for(int i=0; i<adj.size(); i++)
        {
            cout<<i<<"  ";
            for(auto j: adj[i])
            {
                cout<<"("<<j.first<<", "<<j.second<<") ";
            }
            cout<<endl;
        }
    vector<int> dist(vertices);
    for(int i=0; i<vertices; i++)
    {
        dist[i] = INT_MAX;
    }

    set<pair<int,int>> st;
    st.insert(make_pair(0,source));

    dist[source] = 0;
    while (!st.empty())
    {
        auto top = *(st.begin());
        int nodeDistance = top.first;
        int topNode = top.second;

        st.erase(st.begin());
        for(auto neighbour : adj[topNode])
        {
            if(nodeDistance + neighbour.second < dist[neighbour.first])
            {
                auto record = st.find(make_pair(dist[neighbour.first],neighbour.first));
                if(record != st.end())
                {
                    st.erase(record);
                }
                dist[neighbour.first]  = nodeDistance + neighbour.second;
                st.insert(make_pair(dist[neighbour.first],neighbour.first));
            }
        }
    }
    for(int i=0; i<dist.size(); i++)
    {
        cout<<dist[i]<<endl;
    }
    return dist;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int edges;
    cin>>edges;
    vector<vector<int>> vec;

    for(int i=0; i<edges; i++)
    {
        vector<int> temp;
        for(int j=0; j<=2; j++)
        {
            int u;
            cin>> u;
            temp.push_back(u);
        }
        vec.push_back(temp);
    }

    for(int i=0; i<edges; i++)
    {
        cout<<vec[i][0]<<"  "<<vec[i][1]<<"  "<<vec[i][2]<<endl;
    }
    int vertices,source;
    cin>>vertices>>source;
    vector<int> ans = Dijkstra(vec,edges,vertices,source);

    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<"  ";
    }

    return 0;
}