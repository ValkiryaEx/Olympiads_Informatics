#include <bits/stdc++.h>
 
using namespace std;

const int maxn=1e5+9, maxm=2e5+9;

int in[maxn], out[maxn], ptr[maxm];
vector<int> adj[maxn];
vector<int> path;

void dfs(int u){
    while(ptr[u]<(int)adj[u].size()){
        auto v=adj[u][ptr[u]++];
        dfs(v);
    }
    path.push_back(u);
}

int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        in[b]++; out[a]++;
    }
    int start=0, end=0;
    int odd_count=0;
    for(int i=1;i<=n;i++){
        if(in[i]!=out[i])odd_count++;
        if(in[i]==out[i]+1)end=i;
        if(in[i]+1==out[i])start=i;
    }
    if(odd_count!=2||start!=1||end!=n){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    dfs(1);
    reverse(path.begin(), path.end());
    if((int)path.size()!=m+1){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    for(int i=0;i<(int)path.size();i++){
        cout<<path[i]<<" ";
    }
}
