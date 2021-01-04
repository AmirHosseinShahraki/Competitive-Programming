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
char maze[30][30][30];
bool vis[30][30][30];
int dis[30][30][30];

int moveX[] = {1,-1,0,0,0,0};
int moveY[] = {0,0,1,-1,0,0};
int moveZ[]={0,0,0,0,1,-1};

int lx,ly,lz;

void bfs(tuple<int,int,int> root ){
    memset(vis,0,sizeof(vis));
    memset(dis,0,sizeof(dis));
    int i,j,k;
    tie(i,j,k)=root;
    queue<tuple<int,int,int>>q;
    q.push(root);
    dis[i][j][k]=0;
    vis[i][j][k]=0;
    while(!q.empty()){
        tuple<int,int,int> f = q.front();
        q.pop();
        int c,v,b;
        tie(c,v,b)=f;
        vis[c][v][b]=1;
        for(int i=0;i<6;i++){
            if(c+moveZ[i]>=0 && c+moveZ[i]<lz && v+moveY[i]>=0 && v+moveY[i]<ly && b+moveX[i]>=0 && b+moveX[i]<lx && !vis[c+moveZ[i]][v+moveY[i]][b+moveX[i]] && maze[c+moveZ[i]][v+moveY[i]][b+moveX[i]]!='#'){
                q.push({c+moveZ[i],v+moveY[i],b+moveX[i]});
                dis[c+moveZ[i]][v+moveY[i]][b+moveX[i]]=dis[c][v][b]+1;
                vis[c+moveZ[i]][v+moveY[i]][b+moveX[i]]=1;
                if(maze[c+moveZ[i]][v+moveY[i]][b+moveX[i]]=='E') return;
            }
        }

    }
}

int main(){
    fast;
    //usefiles;
    int l,r,c;
    while(cin>>l>>r>>c){
        if(!l && !r && !c) break;
        lz=l;ly=r;lx=c;
        tuple<int,int,int>s,e;
        for(int i=0;i<l;i++)
            for(int j=0;j<r;j++)
                for(int k=0;k<c;k++){
                    cin>>maze[i][j][k];
                    if(maze[i][j][k]=='S') s = {i,j,k};
                    if(maze[i][j][k]=='E') e = {i,j,k};
                }
        bfs(s);
        int n,m,k;
        tie(n,m,k)=e;
        if(vis[n][m][k]) cout<<"Escaped in "<<dis[n][m][k]<<" minute(s)."<<endl;
        else cout<<"Trapped!\n";
    }
    return 0;
}