#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define N 30
#define md ll(1000000007)
#define pb push_back
#define fi first
#define sc second
#define pop __builtin_popcount

int dp[32][32][32][2] = {0};
int binc[32] = {0};

int main(){
	
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	
	while(t--){
		int a, b, c;
		cin >> a >> b >> c;
		a = pop(a); b = pop(b);
		
		int temp = c;
		for(int i = 0 ; i <= N; i++){
			int bit = temp%2;
			binc[i] = bit;
			temp = temp/2; 
		}
		
		if(binc[0] == 1){
			dp[0][1][0][0] = 1;
			dp[0][0][1][0] = 1;
		}else{
			dp[0][1][1][1] = 1;
			dp[0][0][0][0] = 1;
		}
		
		for(int i =1 ; i<=N; i++){	
			for(int ia = 0; ia <= N; ia++){
				for(int ib = 0; ib <= N; ib++){
					if(binc[i] == 0){
						dp[i][ia][ib][0] += dp[i-1][ia][ib][0];
						dp[i][ia+1][ib][1] += dp[i-1][ia][ib][1];
						dp[i][ia][ib+1][1] += dp[i-1][ia][ib][1];
						dp[i][ia+1][ib+1][1] += dp[i-1][ia][ib][0];
					}else{
						dp[i][ia+1][ib][0] += dp[i-1][ia][ib][0];
						dp[i][ia][ib+1][0] += dp[i-1][ia][ib][0];
						dp[i][ia][ib][1] += dp[i-1][ia][ib][1];
						dp[i][ia+1][ib+1][0] += dp[i-1][ia][ib][1];
					}
				}
			}
		}
		
		for(int i = 0 ; i < 4 ; i++){
			for(int ia = 0 ;ia<4;ia++){
				for(int ib = 0 ;ib<4; ib++){	
					cout << i<<" " << ia <<" "<< ib <<"     "<< dp[i][ia][ib][0] <<"   "<< dp[i][ia][ib][1] << endl;
				}
			}
		}
		
		cout << dp[10][a][b][0]  <<endl;
		
	}	
		
	return 0;
}