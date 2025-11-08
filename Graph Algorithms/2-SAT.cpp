#include <bits/stdc++.h>
 
using namespace std;

const int maxn=3e5;
int scc[maxn], ans[maxn];
vector<int> adj[maxn], adj_rev[maxn], order;
bool vis[maxn];

void add_edge(int a, int b){
    adj[a].push_back(b);
    adj_rev[b].push_back(a);
}

void dfs(int u){
    vis[u]=true;
    for(auto v:adj[u]){
        if(!vis[v])dfs(v);
    }
    order.push_back(u);
}

void Kosaraju(int u, int id){
    scc[u]=id;
    for(auto v:adj_rev[u]){
        if(scc[v]==-1){
            Kosaraju(v, id);
        }
    }
}

int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
        int a, b;
        char c1, c2;
        cin>>c1>>a>>c2>>b;
        a--;b--;
        int nod_a=(a*2)+(c1=='-'), nod_b=(b*2)+(c2=='-');
        int not_a=nod_a^1, not_b=nod_b^1;
        add_edge(not_a, nod_b);
        add_edge(not_b, nod_a);
    }
    int n_vertices=m*2;
    for(int i=0;i<n_vertices;i++){
        if(!vis[i])dfs(i);
    }
    reverse(order.begin(), order.end());
    int comp=0;
    memset(scc, -1, sizeof(scc));
    for(int i=0;i<n_vertices;i++){
        if(scc[order[i]]==-1){
            Kosaraju(order[i], comp++);
        }
    }
    for(int i=0;i<m;i++){
        int nod_a=i*2, nod_b=i*2+1;
        if(scc[nod_a]==scc[nod_b]){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
        ans[i]=scc[nod_a]>scc[nod_b];
    }
    for(int i=0;i<m;i++)
        if(ans[i]){
            cout<<"+ ";
        }else cout<<"- ";
}
