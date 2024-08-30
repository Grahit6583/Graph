#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class graph
{
    public:
        unordered_map<int, list<int>> gt;
        void addedge(int u, int v, bool direction)
        {
            gt[u].push_back(v);
            if(direction == 0)
            {
                gt[v].push_back(u);
            }
        }

        void printedge()
        {
        // for (const auto& pair : gt) {  
        //     cout << pair.first << ": ";
        //     for (const auto& vertex : pair.second) {  
        //         cout << vertex << " ";
        //     }
        //     cout << endl;
        // }
        unordered_map<int,list<int>> :: iterator it;
        for(it = gt.begin(); it != gt.end(); it++)
        {
            cout<<it->first<<"->";
            for(auto j:it->second)
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
        }
};

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cout<<"hello"<<endl;
    cin>>n;
    int m;
    cout<<"world"<<endl;
    cin>>m;
    cout<<m<<endl;
    graph g;
    for(int i=0;i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        g.addedge(u,v,0);
    }

    g.printedge();
    return 0;
}