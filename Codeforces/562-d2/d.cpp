#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod ll(1000000007)
#define mod1 ll(998244353)
#define mox ll(200005)
#define inf ll(1e18)
#define fol(i,a,b) for(ll i=a; i<b; i++)
#define vll vector<ll>
#define mk make_pair
#define pb push_back
#define po pop_back
#define ff first
#define ss second
#define bb begin()
#define ee end()


ll gcd(ll a, ll b){
	if(b==0) return a;
	if(a==0) return b;
	return gcd(b,a%b);
}
ll pw(ll x, ll y){ 
    	if(y==0)	return 1; 
	ll r=pw(x,y/2);
    	if(y%2==0) 	return r*r; 
    	else		return x*r*r; 
}


int main()
{
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n; cin>>n;
	vector < pair<ll,ll> > s(n);
	vll t(n);
	fol(i,0,n){
		cin>>s[i].ff;
		s[i].ss=i+1;
	}
	fol(i,0,n){
		cin>>t[i];
	}
	sort(s.bb, s.ee);
	sort(t.bb, t.ee);
	ll diff=0;
	vector < pair < pair<ll,ll> , ll > > ans;
	stack < pair<ll,ll> > st;
	fol(i,0,n){
		ll dist=t[i]-s[i].ff;
		diff+=dist;
		if(diff<0){
			cout<<"NO\n";
			return 0;
		}
		if(dist<0){
			dist=-dist;
			while(dist>0){
				pair<ll,ll> p1=st.top();
				st.pop();
				if(p1.ff>dist){
					p1.ff-=dist;
					st.push(p1);
					ans.pb(mk(mk(p1.ss, s[i].ss), dist));
					dist=0;
				}
				else{
					dist-=p1.ff;
					ans.pb(mk(mk(p1.ss, s[i].ss), p1.ff));                                                                         
				}
			}
		}
		else if(dist>0){
			st.push(mk(dist, s[i].ss));
		}
	}
	if(diff>0){
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n"<<ans.size()<<"\n";
	fol(i,0,ans.size()){
		cout<<ans[i].ff.ff<<" "<<ans[i].ff.ss<<" "<<ans[i].ss<<"\n";
	}
	return 0;
}