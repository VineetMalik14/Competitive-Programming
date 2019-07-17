#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod ll(1000000007)
#define mod1 ll(998244353)
#define mox ll(200005)
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
	ios :: sync_with_stdio(false); 
	cin.tie(0); cout.tie(0);

	ll k1, k2; cin>>k1>>k2;
	k1--; k2--;
	vector < pair<ll,ll> > v(666);
	ll pos[999][999]={0};
	vll r(999), c(999);

	ll s1[8]={1,1,0,-1,-1,-1,0,1}, s2[8]={0,1,1,1,0,-1,-1,-1};

	fol(i,0,666){
		ll x, y; cin>>x>>y;
		x--; y--;
		v[i].ff=x;
		v[i].ss=y;
		r[x]++; c[y]++;
		pos[x][y]=1;
	}
	ll r1=0, c1=0;
	fol(i,1,999){
		if(r[r1]<r[i]){
			r1=i;
		}
		if(c[c1]<c[i]){
			c1=i;
		}
	}

	ll j1=0, j2=0;

	if(k1>r1){
		j1--;
	}
	else{
		j1++;
	}
	if(k2>c1){
		j2--;
	}
	else{
		j2++;
	}

	ll i1=0;
	fol(i,0,8){
		if(j1==s1[i] && j2==s2[i]){
			i1=i;
			break;
		}
	}

	for(ll i=i1; i<i1+8; i++){
		if(!pos[k1+s1[i%8]][k2+s2[i%8]]){
			j1=s1[i%8]; j2=s2[i%8];
			break;
		}
	} 

	k1+=j1; k2+=j2;
	cout<<k1+1<<" "<<k2+1<<endl;
	ll p, x, y;
	cin>>p>>x>>y;


	while(p!=-1){

		fflush(stdout);

		p--; x--; y--;

		pos[v[p].ff][v[p].ss]=0;
		pos[x][y]=1;
		r[v[p].ff]--;
		c[v[p].ss]--;
		v[p].ff=x;
		v[p].ss=y;
		r[x]++; 
		c[y]++;

		ll r1=0, c1=0;
		fol(i,1,999){
			if(r[r1]<r[i]){
				r1=i;
			}
			if(c[c1]<c[i]){
				c1=i;
			}
		}

		ll j1=0, j2=0;

		if(k1>r1){
			j1--;
		}
		else{
			j1++;
		}
		if(k2>c1){
			j2--;
		}
		else{
			j2++;
		}

		ll i1=0;
		fol(i,0,8){
			if(j1==s1[i] && j2==s2[i]){
				i1=i;
				break;
			}
		}

		for(ll i=i1; i<i1+8; i++){
			if(!pos[k1+s1[i%8]][k2+s2[i%8]]){
				j1=s1[i%8]; j2=s2[i%8];
				break;
			}
		} 

		k1+=j1; k2+=j2;
		cout<<k1+1<<" "<<k2+1<<endl;
		cin>>p>>x>>y;
	}
	return 0;
}