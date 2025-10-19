//Nota mental usar '\n' en lugar de endl puede hacer mucha diferencia
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN=2e5;
int n;
vector<int> x;
vector<vector<int>> st;

int que(int ts, int te, int l, int r){
    ts+=n;
    te+=n;
    int ans=0;
    while(ts<te){
        if(ts&1){
            ans+=upper_bound(st[ts].begin(), st[ts].end(),r)-
                 lower_bound(st[ts].begin(), st[ts].end(),l);
            ts++;
        }
        if(te&1){
            te--;
            ans+=upper_bound(st[te].begin(), st[te].end(),r)-
                 lower_bound(st[te].begin(), st[te].end(),l);
        }
        ts>>=1;te>>=1;
    } 
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;cin>>n>>q;
    x.resize(n);
    st.resize(n*2, vector<int>());
    for(int i=0;i<n;i++){
        cin>>x[i];
        st[i+n]=vector<int>(1,x[i]);
    }
    for(int i=n-1;i>=1;i--){
        st[i].resize(st[i<<1].size()+st[i<<1|1].size());
        merge(st[i<<1].begin(), st[i<<1].end(), st[i<<1|1].begin(),
              st[i<<1|1].end(), st[i].begin());
    }
    while(q--){
        int a,b,c,d;cin>>a>>b>>c>>d;
        a--;b--;
        cout<<que(a,b+1,c,d)<<endl;
    }
}
