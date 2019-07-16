#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod ll(1000000007)
#define mox ll(200005)
#define fol(i,a,b) for(ll i=a; i<b; i++)
#define mk make_pair
#define pb push_back
#define po pop_back
#define vll vector<ll>
#define ff first
#define ss second

ll gcd(ll a , ll b){
	if(b==0) return  a;
	if(a==0) return b;
	return gcd(b,a%b) ;
}
ll pw(ll a, ll b){
	ll ans=1;
	a%=mod; 
	assert(b>=0);
	for(;b;b>>=1){
		if(b&1){
			ans=ans*a%mod;
			a=a*a%mod;
		}
	}
	return ans;
}

vector< pair<ll,ll> > v[mox];

ll dfs(ll x, ll y){
        if(v[y].size()==1){
                return 0;
        }
        ll mx=0;
        fol(i,0,v[y].size()){
                if(v[y][i].ss!=x){
                        v[y][i].ff=1+dfs(y,v[y][i].ss);
                        mx=max(mx,v[y][i].ff);
                }
        }
        return mx;
}

int main(){
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n ; cin>>n;
        vll x1(n-1), x2(n-1);
        fol(i,0,n-1){
                cin>>x1[i]>>x2[i];
                v[x1[i]].pb(mk(0,x2[i]));
                v[x2[i]].pb(mk(0,x1[i]));
        }
        fol(i,0,v[1].size()){
                v[1][i].ff=1+dfs(1,v[1][i].ss);
        }
        fol(i,1,n+1){
                sort(v[i].begin(), v[i].end());
        }
        fol(i,1,n+1){
                fol(j,0,v[i].size()){
                        if(v[i][j].ff==0){
                                ll k1=v[i][j].ss;
                                if(v[k1][v[k1].size()-1].ss!=i){
                                        v[i][j].ff=1+v[k1][v[k1].size()-1].ff;
                                }
                                else if(v[k1].size()>=2){
                                        v[i][j].ff=1+v[k1][v[k1].size()-2].ff;
                                }
                                else{
                                        v[i][j].ff=1;
                                }
                        }
                }
        }
        ll ans=0, pr1=0, pr2=0, pr3=0, pr4=0;
        fol(i,0,n-1){
                if(v[x1[i]].size()>1 && v[x2[i]].size()>1){
                        ll w1, w2=x1[i], w3, w4=x2[i];
                        ll r1=0, j=0;
                        ll ar1=0;
                        while(r1<2 && j>=0){
                                if(v[x1[i]][j].ss!=x2[i]){
                                        if(r1==0){
                                                w1=v[x1[i]][j].ss;
                                                r1++;
                                                ar1+=v[x1[i]][j].ff;
                                        }
                                        else{
                                                w2=v[x1[i]][j].ss;
                                                r1++;
                                                ar1+=v[x1[i]][j].ff;
                                        }
                                }
                                j--;
                        }
                        r1=0; j=0;
                        while(r1<2 && j>=0){
                                if(v[x2[i]][j].ss!=x1[i]){
                                        if(r1==0){
                                                w3=v[x2[i]][j].ss;
                                                r1++;
                                                ar1+=v[x2[i]][j].ff;
                                        }
                                        else{
                                                w4=v[x2[i]][j].ss;
                                                r1++;
                                                ar1+=v[x2[i]][j].ff;
                                        }
                                }
                                j--;
                        }
                        if(ar1>ans){
                                ans=ar1;
                                pr1=w1; pr2=w2; pr3=w3; pr4=w4;
                        }
                }
        }
        cout<<pr1<<" "<<pr2<<endl;
        cout<<pr3<<" "<<pr4<<endl;
	return 0;
}