#include <bits/stdc++.h>
 
using namespace std;

const int maxn=1e5+9, maxm=2e5+9;

int degree[maxn], ptr[maxm];
vector<pair<int,int>> adj[maxn];
vector<int> path;
bool used[maxm];

void dfs(int u){
    while(ptr[u]<(int)adj[u].size()){
        auto [v, id]=adj[u][ptr[u]++];
        if(used[id])continue;
        used[id]=true;
        dfs(v);
    }
    path.push_back(u);
}

int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back({b,i});
        adj[b].push_back({a,i});
        degree[a]++; degree[b]++;
    }
    bool eulerian_cycle=true;
    for(int i=1;i<=n;i++){
        if(degree[i]%2)eulerian_cycle=false;
    }
    if(!eulerian_cycle){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    } 
    dfs(1);
    if(path.size()!=m+1){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    for(int i=0;i<(int)path.size();i++){
        cout<<path[i]<<" ";
    }
}
