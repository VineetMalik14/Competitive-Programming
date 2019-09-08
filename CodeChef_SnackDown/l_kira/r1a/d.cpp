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
#define pop __builtin_popcount

int arr[N] = {0};

ll gcd(ll a, ll b){
	if(a == 0) return b;
	if(b == 0) return a;
	return gcd(b,a%b);
}

int main(){
	
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
        freopen("input.txt", "r", stdin);
	int t; cin >> t;
	
	while(t--){
		fill(arr,arr+N, 0);
		int n;
		cin >> n;
		
		int first = 0, pri =0, g = 0;
		for(int i = 1 ; i<=n; i++){
			cin >> arr[i];
			if(arr[i] == -1) continue;
			if(pri == 0){pri = i; first = i;}
			else{
				g = gcd(g,i+arr[pri]-pri-arr[i]);
				pri = i;
			}
		}
		
		//cout << "g " << g << endl;
		
		arr[0] = 1;
		if(g == 0){
			if(arr[first] >= first) cout << "inf" <<endl;
			else cout << arr[first] - first + n << endl;
			continue;
		}
		int x = arr[first];
		for(int i = first; i<=n; i++, x++){
			if(x > g) x = 1;
			if(arr[i] == -1) continue;
			if(arr[i] != x) {
				cout << "impossible" << endl;
				g = 0; break;
			}
		}
		
		if(g) cout << g <<endl;
						
	}	
		
	return 0;
}