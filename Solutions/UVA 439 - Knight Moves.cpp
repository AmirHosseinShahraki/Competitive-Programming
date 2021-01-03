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

int dis[8][8];
bool vis[8][8];

int moveX[] = {2,2,-2,-2,1,1,-1,-1};
int moveY[] = {1,-1,1,-1,2,-2,2,-2};

void bfs(int n,int m){
    memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis));
    queue<pii>q;
    q.push({n,m});
    dis[n][m]=0;
    vis[n][m]=1;
    while(!q.empty()){
        pii f = q.front();
        q.pop();
        int k=f.first,l=f.second;
        vis[k][l]=1;
        for(int i=0;i<8;i++){
            if(k+moveY[i]>=0 && k+moveY[i]<8 &&  l+moveX[i]>=0 && l+moveX[i]<8 && !vis[k+moveY[i]][l+moveX[i]]){
                q.push({k+moveY[i],l+moveX[i]});
                dis[k+moveY[i]][l+moveX[i]]=dis[k][l]+1;
            }

        }
    }

}


int main(){
    fast;
    string fm,sm;
    while(cin>>fm>>sm){
        bfs(fm[0]-'a',fm[1]-'0'-1);
        cout<<"To get from "<<fm<<" to "<<sm<<" takes "<<dis[sm[0]-'a'][sm[1]-'0'-1]<<" knight moves.\n";
    }
    return 0;
}