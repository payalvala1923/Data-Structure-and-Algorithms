#include <bits/stdc++.h>
using namespace std;
#define minv(v) *min_element(v.begin(), v.end())
#define maxv(v) *max_element(v.begin(), v.end())
#define sumv(v) accumulate(v.begin(), v.end(), 0LL)
#define ll long long

class Disjointset{
    vector<ll> rank, parent,size;
public:
    Disjointset(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;++i){
            parent[i]=i;
            size[i]=1;
        }
    }
    //path compression
    ll findPar(ll node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findPar(parent[node]);
    }

    void unionByRank(int u, int v){
        ll ulp_u=findPar(u);
        ll ulp_v=findPar(v);
        if(ulp_v=ulp_u) return;
        else if(rank[ulp_u]>rank[ulp_v]) {
            parent[ulp_v]=ulp_u;
        }
        else if(rank[ulp_v]>rank[ulp_u]) {
            parent[ulp_u]=ulp_v;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }

     void unionBySize(ll u, ll v){
        ll ulp_u=findPar(u);
        ll ulp_v=findPar(v);

        if(ulp_v=ulp_u) return;
        else if(size[ulp_v]>size[ulp_u]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
int main(){
    Disjointset ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    
    if(ds.findPar(3)==ds.findPar(7)) 
        cout<<"Same Component\n";
    else 
        cout<<"Not same\n";

    ds.unionBySize(3,7);

    if(ds.findPar(3)==ds.findPar(7)) 
        cout<<"Same Component\n";
    else 
       cout<<"Not same\n";

 
}
