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

ll n, cnt, bound;
string s;

ll solve(ll pos, ll tar, ll ty){
        if(pos==tar){
                bound=max(bound, pos);
                return 0;
        }
        if(ty==0){
                ll p=-1;
                bound=max(bound, pos+1);
                if(pos+1<n){
                        if(s[pos+1]=='#'){
                                cnt++;
                                p=solve(pos+1, pos+2, 1);
                        }
                        else{
                                p=0;
                        }
                }
                if(p==-1){
                        return -1;
                }
                else{
                        return pos-tar+p;
                }
        }
        if(ty==1){
                ll p=-1, j=pos+1, k1=0;
                ll c1=cnt;
                bound=max(bound, tar+1);
                while(j<=tar+1 && j<n){
                        if(s[j]=='#'){
                                cnt++;
                                p=solve(j, tar+2, 1);
                                break;
                        }
                        else{
                                k1++;
                        }
                        j++;
                }
                if(k1==tar+1-pos){
                        p=0;
                }
                if(p==-1){
                        return -1;
                }
                else{
                        return tar-pos+p+tar-c1;
                }
        }
}
int main(){
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll t; cin>>t;
        while(t--){
                cin>>n;
                cin>>s;
                ll p=0, ans=0;
                cnt=0; bound=-1;
                fol(i,0,n){
                        if(s[i]=='#'){
                                if(i>bound){
                                        p=solve(i, cnt, 0);
                                        //cout<<i<<":"<<p<<endl;
                                        if(p==-1){
                                                break;
                                        }
                                        ans+=p;
                                        cnt++;
                                }
                        }
                }
                if(p==-1){
                        cout<<-1<<endl;
                }
                else{
                        cout<<ans<<endl;
                }
        }
	return 0;
}