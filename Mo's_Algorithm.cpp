#include <bits/stdc++.h>
 
using namespace std;

const int MAXN=2e5+9, MAXB=450;
int cnt[MAXN], ans[MAXN];

struct Block{
    int l,r,i;
    bool operator <(const Block &o) const{
        if(l/MAXB==o.l/MAXB)return ((l/MAXB)&1)?r<o.r:r>o.r;
        return l/MAXB<o.l/MAXB;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;cin>>n>>q;
    vector<int> v(n), vv(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        vv[i]=v[i];
    }
    sort(vv.begin(), vv.end());
    vv.erase(unique(vv.begin(), vv.end()), vv.end());
    for(int i=0;i<n;i++){
        v[i]=lower_bound(vv.begin(), vv.end(), v[i])-vv.begin();
    }
    vector<Block> p;
    for(int i=0;i<q;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        p.push_back({a, b, i});
    } 
    sort(p.begin(), p.end());
    int l0=p[0].l, r0=l0;
    cnt[v[l0]]++;
    ans[p[0].i]++;
    for(int i=0;i<q;i++){
        if(i)ans[p[i].i]=ans[p[i-1].i];
        while(l0<p[i].l){
            cnt[v[l0]]--;
            if(cnt[v[l0]]==0){
                ans[p[i].i]--;
            }
            l0++;
        }
        while(l0>p[i].l){
            cnt[v[--l0]]++;
            if(cnt[v[l0]]==1){
                ans[p[i].i]++;
            }
        }
        while(r0<p[i].r){
            cnt[v[++r0]]++;
            if(cnt[v[r0]]==1){
                ans[p[i].i]++;
            }
        }
        while(r0>p[i].r){
            cnt[v[r0]]--;
            if(cnt[v[r0]]==0){
                ans[p[i].i]--;
            }
            r0--;
        }
    }
    for(int i=0;i<q;i++)cout<<ans[i]<<endl;
}
