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
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); 
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;

int n;
vector<vi> g, pref;

void init(){
	forsn(i,1,n+1){
		forsn(j,1,n+1){
			//Formula para calcular submatriz [1, 1] [i, j]
			pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + 
			             g[i-1][j-1];
		}
	}
}

ll get(int b, int a, int B, int A){
	//Formula para obtener submatriz [a, b] [A, B] usando prefix sum
	return pref[A][B] - pref[A][b-1] - pref[a-1][B] + 
	       pref[a-1][b-1];
}

int main(){FIO;	
	int q;cin>>n>>q;
	g.resize(n, vi(n, 0));
	pref.resize(n+1, vi(n+1, 0));
	forn(i,n){
		string s;
		cin>>s;
		forn(j,n){
			if(s[j]=='*'){
				g[i][j]++;
			}
		}
	}
	//Inicializar matriz 
	init();
	while(q--){
		int y1, x1, y2, x2;
		cin>>y1>>x1>>y2>>x2;
		cout<<get(x1, y1, x2, y2)<<endl;	
	}
}
