#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define N 1000005
#define md ll(1000000007)
#define pb push_back
#define fi first
#define sc second

int arr[105] = {0};
int uh[105][105] = {0};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll grand(ll x) {
    return uniform_int_distribution<ll>(0, x - 1)(rng);
}

ll gcd(ll a , ll b){
	if(b==0) return  a;
	if(a == 0 ) return b;
	return gcd(b,a%b) ;
}

int n;

int uhp(int i, int j){
	if(uh[i][j] != md) return uh[i][j];
	
	int il = 0, ir= 0, jl = 0, jr = 0;
	for(int k = 0; k <n ; k++){
		if(k == i){k = j; continue;}
		if(arr[i] > arr[k]) il++;
		if(arr[i] < arr[k]) ir++;
		if(arr[j] > arr[k]) jl++;
		if(arr[j] < arr[k]) jr++;
	}
	il = min(il,ir);
	jl = min(jl,jr);
	if(i == j){
		uh[i][j] = il;
		return uh[i][j];
	}
	uh[i][j] = min(uhp(i+1,j) + il , uhp(i,j-1) + jl);
	return uh[i][j];	
}

int main(){
	
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
		
	ll m = 0, k = 0, q = 0, ans = 0;
	ll x = 0, y = 0, t = 0, sum = 0, sz = 0;
	
	cin >> t;
	
	while(t--){
		cin >> n;
		fill(arr, arr + 105 , 0);
		
		for(int i = 0 ;i <105 ; i++){
			for(int j = 0 ; j < 105 ; j++){
				uh[i][j] = md;
			}
		}
		
		for(int i = 0; i <n ;i++){
			cin >> arr[i];
		}
		cout << uhp(0,n-1) <<endl;		
	}		
	return 0;
}