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


int main()
{
    
    fast;
    int n;
    cin>>n;
    n = (1<<n);
    vi v(n);
    input(v);
    vi ans;
    vi srt=v;
    msort(srt);
    bool flag=false;
    while(1){
        if(flag) break;
        for(int i=0;i<n-1;i++){
             if(flag) break;
        for(int j=i+1;j<n;j++){
             if(flag) break;
            if(v[i]>v[j] && __builtin_popcount(i^j)==1){
                ans.push_back(i);
                ans.push_back(j);
                swap(v[i],v[j]);
                if(srt==v) flag = true;
            }
        }
    }
    }
    cout<<ans.size()/2<<NL;
    for(int i=0;i<ans.size();i+=2){
        cout<<ans[i]<<' '<<ans[i+1]<<NL;
    }
    return 0;
}



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


int main()
{
    
    fast;
    int n;
    cin>>n;
    return 0;
}