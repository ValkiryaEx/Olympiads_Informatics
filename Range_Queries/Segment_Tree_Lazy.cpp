#include <bits/stdc++.h>
 
using namespace std;

const int MAXN=2e5+9;
long long st[MAXN*4], lazy_inc[MAXN*4], lazy_set[MAXN*4];
int n;

void propagate(int v, int s, int e){
    if(lazy_set[v]!=0){
        st[v]=lazy_set[v]*(e-s+1);
        if(s!=e){
            lazy_set[v*2]=lazy_set[v*2+1]=lazy_set[v];
            lazy_inc[v*2]=lazy_inc[v*2+1]=0;
        }
        lazy_set[v]=0;
    }
    if(lazy_inc[v]!=0){
        st[v]+=lazy_inc[v]*(e-s+1);
        if(s!=e){
            lazy_inc[v*2]+=lazy_inc[v];
            lazy_inc[v*2+1]+=lazy_inc[v];
        }    
        lazy_inc[v]=0;
    }
}

void build(const vector<long long> &a, int v=1, int s=0, int e=n-1){
    if(s==e){
        st[v]=a[s];
        return;
    }
    int m=(s+e)/2;
    build(a,v*2,s,m);
    build(a,v*2+1,m+1,e);
    st[v]=st[v*2]+st[v*2+1];
}

void upd(const int &ts, const int &te, int x, bool f, int v=1, int s=0, int e=n-1){
    propagate(v,s,e);
    if(e<ts||te<s)return;
    else if(ts<=s&&e<=te){
        if(!f)lazy_inc[v]=x;
        else lazy_set[v]=x;
        propagate(v,s,e);
        return;
    }
    int m=(s+e)/2;
    upd(ts,te,x,f,v*2,s,m);
    upd(ts,te,x,f,v*2+1,m+1,e);
    st[v]=st[v*2]+st[v*2+1];
}

long long que(const int &ts, const int &te, int v=1, int s=0, int e=n-1){
    propagate(v,s,e);
    if(e<ts||te<s)return 0;
    else if(ts<=s&&e<=te){
        return st[v];
    }
    int m=(s+e)/2;
    return que(ts,te,v*2,s,m)+que(ts,te,v*2+1,m+1,e);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;cin>>n>>q;
    vector<long long> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    build(v);
    while(q--){
        int t;cin>>t;
        t--;
        if(t==2){
            int a,b;cin>>a>>b;
            a--;b--;
            cout<<que(a,b)<<endl;
        }else{
            int a,b,x;cin>>a>>b>>x;
            a--;b--;
            upd(a,b,x,t);            
        }
    }
}
