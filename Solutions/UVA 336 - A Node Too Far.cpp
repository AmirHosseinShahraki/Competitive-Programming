#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
#define fast ios::sync_with_stdio(0);cin.tie(NULL)
#define PB push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define input(x) for(auto &i : x) cin>>i
#define output(x) for(auto i : x) cout<<i<<' '
#define NL '\n'
#define SP(x,z) fixed<<setprecision(z)<<x
#define PI 3.14159265358979323846
#define msort(x) sort(x.begin(),x.end())
#define mrsort(x) sort(x.rbegin(),x.rend())
#define all(x) x.begin(),x.end()
#define usefiles freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
map<int,vector<int>> adj;
map<int,int>dis;
map<int,int>vis;
void bfs(int root){
    dis.clear();
    vis.clear();
    queue<int>q;
    q.push(root);
    dis[root]=0;
    while(!q.empty()){
        int f=q.front();
        vis[f]=1;
        q.pop();
        for(int i=0;i<adj[f].size();i++){
            if(!vis[adj[f][i]]){
                vis[adj[f][i]]=1;
                dis[adj[f][i]]=dis[f]+1;
                q.push(adj[f][i]);
            }
        }

    }

}

int main(){
    fast;
    int n;
    int count=0;
    while(1){
        cin>>n;
        if(!n) break;
        adj.clear();
        for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            adj[a].PB(b);
            adj[b].PB(a);
        }
        int m,k;
        while(cin>>m>>k){
            if(!m && !k) break;
            count++;
            bfs(m);
            int c=0;
            for(auto it:dis) if(it.second > k) c++;
            c+=adj.size()-dis.size();
            cout<<"Case "<<count<<": "<<c<<" nodes not reachable from node "<<m<<" with TTL = "<<k<<'.'<<NL;
        }

    }
    return 0;
}