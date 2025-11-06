#include <bits/stdc++.h>
 
using namespace std;

const int maxn=1e5+9;
int tin[maxn], tout[maxn], timer=0, scc[maxn];
vector<int> G[maxn], G_[maxn], order;
bool vis[maxn];

void dfs(int u){
    vis[u]=true;
    tin[u]=timer++;
    for(auto v:G[u]){
        if(!vis[v])dfs(v);
    }
    order.push_back(u);
    tout[u]=timer++;
}

void Kosaraju(int u, int id){
    scc[u]=id;
    for(auto v:G_[u]){
        if(!scc[v])Kosaraju(v,id);    
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G_[b].push_back(a);
    }    
    for(int i=0;i<n;i++){
        if(!vis[i])dfs(i);
    }
    reverse(order.begin(), order.end());
    int comp=1;
    for(int i=0;i<n;i++){
        if(!scc[order[i]]){
            Kosaraju(order[i],comp);
            comp++;
        }
    }
    cout<<comp-1<<endl;
    for(int i=0;i<n;i++)cout<<scc[i]<<" ";
}
