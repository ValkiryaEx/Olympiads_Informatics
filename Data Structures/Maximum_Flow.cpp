#include<bits/stdc++.h>
#define	pb push_back
#define snd second
#define fst first
#define forn(i,n) for(int i=0;i<n;++i)
#define forsn(i,s,n) for(int i=s; i<n; ++i)
#define SZ(c) int((c).size())
#define all(x) x.begin(), x.end()
#define	imp(x) {for(auto __:x)cout<<__<<" "; cout<<endl;}
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "===============================" << endl
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;

const int N=505;
ll capacidad[N][N];
int parent[N];
vector<vector<int>> adj;
ll max_flow(int source, int sink){
	ll max_flow=0;
	memset(parent, -1, sizeof(parent));
	auto bfs=[&]()->bool{
		queue<int> q;
		q.push(source);
		parent[source]=0;
		while(SZ(q)){
			int node=q.front();
			q.pop();
			for(auto son:adj[node]){
				ll w=capacidad[node][son];
				if(w<=0||parent[son]!=-1)
					continue;
				parent[son]=node;
				q.push(son);
			}
		}
		return (parent[sink]!=-1);
	};
 	//mientras exista un camino desde la fuente al sumidero
	while(bfs()){
		ll min_flow=1e18;
		int node=sink;
    		//tomo el menor flujo del camino
		while(node!=source){
			min_flow=min(min_flow, capacidad[parent[node]][node]);
			node=parent[node];
		}
		max_flow+=min_flow;
		node=sink;
   		//se lo resto al camino
		while(node!=source){
			capacidad[node][parent[node]]+=min_flow;
			capacidad[parent[node]][node]-=min_flow;
			node=parent[node];
		}
		memset(parent, -1, sizeof(parent));
	}
	return max_flow;
}
int main(){	
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int n, m;
	cin>>n>>m;
	adj.resize(n+1);
	forn(i,m){
		int u,v,c;
		cin>>u>>v>>c;
		adj[u].pb(v);
		adj[v].pb(u);
		capacidad[u][v]+=c;
	}
	cout<<max_flow(1, n)<<endl;
}	
