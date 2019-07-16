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

ll gcd(ll a, ll b){
	if(b==0) return a;
	if(a==0) return b;
	return gcd(b,a%b);
}
ll binarySearch(ll a[], ll l, ll r, ll x){
        ll mid=(l+r)/2;
        if(x>a[mid]){
                return binarySearch(a,mid+1,r,x);
        }else if(x<a[mid]){
                return binarySearch(a,l,mid-1,x);
        }else if(x==a[mid]){
                return mid;
        }else{
                return 0;
        }
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


int main(){
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll t; cin>>t;
        while(t--){
                ll n, m; cin>>n>>m;
                vll a(n), b(m);
                ll p=0, s1=0, s2=0;
                fol(i,0,n){
                        cin>>a[i];
                        s1+=a[i];
                }
                fol(i,0,m){
                        cin>>b[i];
                        s2+=b[i];
                }
                sort(a.begin(), a.end());
                sort(b.begin(), b.end());
                if(s1!=s2){
                        p=1;
                }
                else{
                        ll i=n-1, j=m-1;
                        while(i>=0 && j>=0){
                                if(a[i]!=b[j]){
                                        p=1;
                                        break;
                                }
                                i--; j--;
                        }
                }
                if(p){
                        cout<<"Alice\n";
                }
                else{
                        cout<<"Bob\n";
                }
        }
	return 0;
}