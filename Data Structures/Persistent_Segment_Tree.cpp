#include<bits/stdc++.h>
#define pb push_back
#define snd second
#define fst first
#define forn(i,n) for(int i=0;i<n;++i)
#define forsn(i,UwU,n) for(int i=UwU; i<n; ++i)
#define SIZE(c) int((c).size())
#define all(x) x.begin(), x.end()
#define imp(x) {for(auto __:x)cout<<__<<" "; cout<<endl;}

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "===============================" << endl

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;

inline void FIO() {ios_base::sync_with_stdio(false); cin.tie(NULL);} 

struct Node{
	ll val;
	Node *l, *r;
	Node(ll x):val(x),l(nullptr),r(nullptr){}//Declaración de hoja
	Node(Node *l_child, Node *r_child){//Declaración de hijos
		l=l_child, r=r_child;
		val=0;
		//Suma de los rangos
		if(l)val+=l->val;
		if(r)val+=r->val;
	}
	Node(Node *copia):val(copia->val),l(copia->l),r(copia->r){}//Copiar nodo
};

int n, sig;
int a[200100];
Node *root[200100];

Node *build(int l=1, int r=n){//Construir Seg Tree
	if(l==r)return new Node(a[l]);
	int m=(l+r)/2;
	return new Node(build(l,m), build(m+1, r));
}

Node *update(Node *nodo, int pos, int val, int l=1, int r=n){
	if(l==r)return new Node(val);
	int m=(l+r)/2;
	if(pos>m)return new Node(nodo->l, update(nodo->r, pos, val, m+1, r));
	else return new Node(update(nodo->l, pos, val, l, m), nodo->r);
}

ll query(Node *nodo, int ll, int rr, int l=1, int r=n){
	if(r<ll||rr<l)return 0;
	if(l>=ll&&r<=rr)return nodo->val;
	int m=(r+l)/2;
	return query(nodo->l, ll, rr, l, m)+query(nodo->r, ll, rr, m+1, r);
}	

int main(){FIO;
	sig=1;
	int q;cin>>n>>q;
	forsn(i,1,n+1)cin>>a[i];
	root[sig++]=build();
	while(q--){
		int o;cin>>o;
		if(o==1){
			int k,x,a;cin>>k>>x>>a;
			//Update en la copia k
			root[k]=update(root[k],x,a);
		}else if(o==2){
			int k,a,b;cin>>k>>a>>b;
			cout<<query(root[k], a, b)<<endl;
		}else{
			int k;cin>>k;
			//Crear copia
			root[sig++]=new Node(root[k]);
		}
	}
}
