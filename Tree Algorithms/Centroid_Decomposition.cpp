#include <bits/stdc++.h>
 
using namespace std;

const int MAXN=1e5+9, INF=1e9;
vector<int> adj[MAXN];
int n, sz[MAXN], bst[MAXN]; 
bool rmv[MAXN];
vector<pair<int,int>> anc[MAXN];

int dfsGetSizes(int u, int p=-1){
    sz[u]=1;
    for(auto v:adj[u]){
        if(v==p||rmv[v])continue;
        sz[u]+=dfsGetSizes(v,u);
    }
    return sz[u];
}

int dfsGetCentroid(int u, int treeSize, int p=-1){
    for(auto v:adj[u]){
        if(v==p||rmv[v])continue;
        if(sz[v]>treeSize/2) return dfsGetCentroid(v,treeSize,u);    
    }
    return u;
}

void dfsGetDistances(int u, int centroid, int p, int d=1){
    for(int v:adj[u]){
        if(v==p||rmv[v])continue;
        d++;
        dfsGetDistances(v,centroid,u,d);
        d--;
    }
    anc[u].push_back({centroid,d});
}

void dfsCentroidDecomposition(int u=0){
    int centroid=dfsGetCentroid(u, dfsGetSizes(u));
    for(int v:adj[centroid]){
        if(rmv[v])continue;
        dfsGetDistances(v,centroid,centroid);
    }
    rmv[centroid]=true;
    for(int v:adj[centroid]){
        if(rmv[v])continue;
        dfsCentroidDecomposition(v);
    }
}

void paint(int u){
    for(auto [v,d]:anc[u]){
        bst[v]=min(bst[v],d);
    }
    bst[u]=0;
}

int query(int u){
    int ans=bst[u];
    for(auto [v,d]:anc[u]){
        ans=min(ans, d+bst[v]);
    }
    return ans;
}

int main(){
    int q;cin>>n>>q;
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0;i<MAXN;i++)bst[i]=INF;
    dfsCentroidDecomposition();
    paint(0);
    while(q--){
        int t,v;cin>>t>>v;
        v--;
        if(t==1){
            paint(v);
        }else{
            cout<<query(v)<<endl;
        }
    }
}
