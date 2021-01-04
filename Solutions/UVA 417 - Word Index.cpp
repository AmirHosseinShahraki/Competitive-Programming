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

int main(){
    fast;
    map<string,int>mp;
    int c=1;
    queue<string>q;
    string s="";
    q.push(s);
    for(char i='a';i<='z';i++){
        s="";
        s+=i;
        mp[s]=c;
        c++;
        q.push(s);
    }
    while(!q.empty()){
        string t = q.front();
        q.pop();
        if(t.size()==5) break;
        for(char i='a';i<='z';i++){
            if(t[t.size()-1] < i){
                s=t;
                s+=i;
                mp[s]=c;
                c++;
                q.push(s);
            }
        }
    }
    string n;
    while(cin>>n)
        cout<<mp[n]<<NL;
    return 0;
}