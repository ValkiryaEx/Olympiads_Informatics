#include <bits/stdc++.h> 

using namespace std;

const int MAXN=200005;
vector<int> adj[MAXN];
int st[MAXN*4], tam[MAXN], dep[MAXN], anc[MAXN], top[MAXN], id[MAXN], v[MAXN], n;

void upd(int idx, int x){
    int v=idx+n;
    st[v]=x;
    while(v/=2){
        st[v]=max(st[v*2], st[v*2+1]);
    }    
}

int que(int l, int r){
    int res=0;
    r++;
    for(l+=n,r+=n;l<r;l/=2,r/=2){
        if(l%2)res=max(res,st[l++]);
        if(r%2)res=max(res,st[--r]);
    }
    return res;
}

int dfs(int u, int p, int d){
    tam[u]=1;
    dep[u]=d;
    anc[u]=p;
    for(auto v:adj[u]){
        if(v==p)continue;
        tam[u]+=dfs(v,u,d+1);
    }
    return tam[u];
}

int nxt=1;

void dfsDecomposition(int u, int p, int sou){
    id[u]=nxt++;
    top[u]=sou;
    upd(id[u],v[u]);
    pair<int,int> hvy={-1,-1};
    for(auto v:adj[u]){
        if(v==p)continue;
        hvy=max(hvy, {tam[v], v});
    }
    if(hvy.second==-1){
        return;
    }
    dfsDecomposition(hvy.second,u,sou);
    for(auto v:adj[u]){
        if(v==p||hvy.second==v)continue;
        dfsDecomposition(v,u,v);
    }
}

int HLD(int a, int b){
    int ret=0;
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]])swap(a,b);
        ret=max(ret, que(id[top[a]], id[a]));
        a=anc[top[a]];
    }
    if(dep[a]>dep[b])swap(a,b);
    ret=max(ret, que(id[a], id[b]));
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;cin>>n>>q;    
    for(int i=1;i<=n;i++)cin>>v[i];
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0,0);
    dfsDecomposition(1,1,1);
    while(q--){
        int t;cin>>t;
        if(t==1){
            int s,x;cin>>s>>x;
            v[s]=x;
            upd(id[s],x);
        }else{
            int a,b;cin>>a>>b;
            cout<<HLD(a,b)<<" ";
        }
    }
}
