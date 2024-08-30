#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> shortest_path(vector<pair<int,int>>edges,int n, int m, int s, int t)
{
    unordered_map<int,list<int>> adj;
    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    queue<int> q;

    parent[s] = -1;
    q.push(s);
    visited[s] = true;
    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        for(auto i:adj[front])
        {
            if(!visited[i])
            {
                parent[i] = front;
                visited[i] = true;
                q.push(i);
            }
        }
    }

    vector<int> ans;
    int currentnode = t;
    ans.push_back(t);
    while(currentnode != s)
    {
        currentnode = parent[currentnode];
        ans.push_back(currentnode);
    }    

    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<pair<int,int>> edges;
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        int s,t;
        cin>>s>>t;

        pair<int,int> p1;
        p1 = make_pair(s,t);

        edges.push_back(p1);
    }

    for(int i=0; i<n; i++)
    {
        cout<<edges[i].first<<"--->"<<edges[i].second<<endl;
    }
    int s,t;
    cin>>s>>t;
    vector<int> ans = shortest_path(edges,n,m,s,t);
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<"  ";
    }
    cout<<endl;
    return 0;
}