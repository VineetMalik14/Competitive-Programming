#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define N 100005
#define md ll(1000000007)
#define pb push_back
#define fi first
#define sc second

ll arr[N] = {0};
ll brr[N] = {0};
ll crr[N] = {0};
ll par[N] = {0};
vector < ll > v, v1, v2,pr;
vector < ll > g[N],prm[N];
pair < ll, ll > p;
string str = "";

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll grand(ll x) {
    return uniform_int_distribution<ll>(0, x - 1)(rng);
}

ll gcd(ll a , ll b){
	if(b==0) return  a;
	if(a == 0 ) return b;
	return gcd(b,a%b) ;
}

ll pw(ll a, ll b){
	if(b== 0) return 1;
	if(b == 1) return a;
	ll t = pw(a,b/2);
	if(b%2 == 0) return (t*t)%md;
	return (((t*t)%md)*a)%md;
}

ll pw2(ll a, ll b){
	if(b== 0) return 1;
	if(b == 1) return a;
	ll t = pw2(a,b/2);
	if(b%2 == 0) return (t*t)%(md -1);
	return (((t*t)%md)*a)%(md -1);
}

int count(int n, int x){
	int ans = 0;
	while(1){
		if(n%x == 0){
			ans++;
		}else{
			break;
		}
		n = n/x;
	}
	return ans;
}

int main(){
	
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
		
	ll n = 0, m = 0, k = 0, q = 0, ans = 0;
	ll x = 0, y = 0, t = 0, sum = 0, sz = 0;
	
	for(int i = 2 ; i<N ; i++){
		if(arr[i] == 1) continue;
		pr.pb(i);
		for(int j = i ; j<N ; j+= i){
			arr[j] = 1;
			g[j].pb(i);
		}
	}
	
	cin >> t;
	
	while(t--){
		
		cin >> n;
		
		for(int i : pr){
			prm[i].clear();
		}
		
		for(int i = 0 ; i < n ; i++){
			cin >> x;
			//x = 3331;
			for(int j : g[x]){
				prm[j].pb(x);
			}
		}
		
		for(int i : pr){
			for(int j = 0 ; j < prm[i].size() ; j++){
				//cout <<i <<" "<< prm[i][j] <<" " <<count(prm[i][j],i) <<endl;
				prm[i][j] = count(prm[i][j], i);
			}
			sort(prm[i].begin(), prm[i].end());
		}
		
		for(int i : pr){
			brr[i] = 0;
			x = 0;
			if(prm[i].size() != 0) x = prm[i][0];
			int tot = prm[i].size();
			int prev = 0;
			int cur = 1;
			for( int j = 1 ; j <prm[i].size() ; j++){
				//cout << i <<" " << prm[i][j] <<endl;
				if(prm[i][j] == x){
					cur++;
				}else{
					brr[i] += ((x*(pw2(2,cur) -1 + md -1))%(md-1))*(pw2(2,tot-cur-prev));
					brr[i] += md -1;
					brr[i] %= md-1;
					//cout << x <<" " <<cur <<" " << tot-cur-prev << " " << prev <<endl;
					prev += cur;
					cur = 1;
					x = prm[i][j];
				}
			}
			//if(i <5) cout << x <<" " <<cur <<" " << tot-cur-prev << " " << prev <<endl;
			brr[i] += ((x*(pw2(2,cur) -1 + md -1))%(md-1))*(pw2(2,tot-cur-prev));
			brr[i] += md -1;
			brr[i] %= md -1;
		}
		
		ll ans = 1;
		for(int i : pr){
			ans *= pw(i,brr[i]);
			ans %= md;
			if(i<5)cout << i <<" "<< brr[i] << endl;
		}
		
		cout << ans <<endl;
		
	}
	
	
	
	
		
	return 0;
}