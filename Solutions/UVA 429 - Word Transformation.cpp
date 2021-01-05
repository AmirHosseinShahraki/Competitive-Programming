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

void bfs(string root,map<string,vector<string>> &mp , map<string,int> &dis , map<string,bool> &vis ){
    dis.clear();
    vis.clear();
    queue<string>q;
    q.push(root);
    dis[root]=0;
    vis[root]=1;
    while(!q.empty()){
        string f = q.front();
        q.pop();
        vis[f]=1;
        for(int i=0;i<mp[f].size();i++){
            if(!vis[mp[f][i]]){
                dis[mp[f][i]]=dis[f]+1;
                vis[mp[f][i]]=1;
                q.push(mp[f][i]);
            }
        }
        
    }
}

int main(){
    fast;
    //usefiles;
    int t;
    cin>>t;
    while(t--){
        map<string,vector<string>>mp;
        map<string,int>dis;
        map<string,bool>vis;
        string s;
        vector<string>w;
        while(cin>>s){
            if(s=="*") break;
            w.push_back(s);
        }
        for(int i=0;i<w.size()-1;i++)
            for(int j=i+1;j<w.size();j++){
                if(w[i].size()==w[j].size()){
                    int dif=0;
                    for(int k=0;k<w[i].size();k++)
                        if(w[i][k]!=w[j][k]) dif++;
                    if(dif==1){
                        mp[w[i]].push_back(w[j]);
                        mp[w[j]].push_back(w[i]);
                    }
                }
            }
        string line;
        getline(cin,line);
        getline(cin,line);
        while(line != ""){
            string start = "",end="";
            bool f=true;
            for(int i=0;i<line.size();i++){
                if(line[i]==' ') {
                    f=false;
                    continue;
                }
                f? start+=line[i] : end+=line[i];
            }
            bfs(start,mp,dis,vis);
            cout<<start<<" "<<end<<" "<<dis[end]<<NL;
            if(!getline(cin,line)) break;
        }
        if(t) cout<<NL;
    }
    return 0;
}