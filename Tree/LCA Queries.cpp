#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ff first
#define ss second

using namespace std;

int depth[112233], par[112233][24];
vector<int> adj[112233];

void dfs(int s, int parnt){
    vector<int>::iterator it;
    par[s][0]=parnt;
    depth[s]=depth[parnt] + 1;
    
    for(it=adj[s].begin();it!=adj[s].end();++it){
        if(*it != parnt){
            dfs(*it, s);
        }
    }
}

void sparseMat(int n){
    for(int i=1;i<=20;i++){
        for(int j=1;j<=n;j++){
            if(par[j][i-1] != -1){
                par[j][i] = par[par[j][i-1]][i-1];
            }
        }
    }
}

int find_lca(int u, int v){
    if(depth[u] > depth[v]){
        swap(u,v);
    }
    
    int diff = depth[v] - depth[u];
    
    for(int i=0;i<20;i++){
        if((diff>>i)&1){
            v=par[v][i];
        }
    }
    
    if(u==v){
        return u;
    }
    
    for(int i=19;i>=0;i--){
        if(par[u][i] != par[v][i]){
            u=par[u][i];
            v=par[v][i];
        }
    }
    
    return par[u][0];
    
}

int main(){
    int t,n,q,i,j,u,v,s,d,p,m;
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    //cin>>t
    
    t=1;
    
    while(t--){
        cin>>n;
        
        m=n-1;
        
        for(i=0;i<=n;i++){
            adj[i].clear();
            depth[i]=0;
        }
        
        for(i=0;i<m;i++){
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        
        memset(par,-1,sizeof(par));
        depth[0]=0;
        depth[1]=1;
        dfs(1,0);
        sparseMat(n);
        
        cin>>q;
        
        while(q--){
            cin>>u>>v;
            p=find_lca(u,v);
            
            cout<<"lca="<<p<<"\n";
         /*Logic based on some question   
            if(p==u || p==1){
                cout<<"Yes\n";
            }
            else{
                cout<<"No\n";
            }*/
        }
        
        
        
    }
    
    return 0;
}
