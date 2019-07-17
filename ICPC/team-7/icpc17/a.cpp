#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod ll(1000000007)
#define mox ll(200005)
#define fol(i,a,b) for(ll i=a; i<b; i++)
#define mk mkae_pair
#define pb push_back
#define po pop_back
#define vll vector<ll>
#define ff first
#define ss second

ll grt(vll a1, vll a2){
        ll p=0;
        fol(i,0,3){
                if(a1[i]>a2[i]){
                        p=1;
                }
                else if(a1[i]<a2[i]){
                        return 0;
                }
        }
        if(p){
                return 1;
        }
        else{
                return 0;
        }
}
int main(){
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll t; cin>>t;
        while(t--){
                vll a1(3), a2(3), a3(3);
                ll p=1;
                fol(i,0,3){
                        cin>>a1[i];
                }
                fol(i,0,3){
                        cin>>a2[i];
                }
                fol(i,0,3){
                        cin>>a3[i];
                }
                if(!grt(a1,a2) && !grt(a2,a1)){
                        p=0;
                }
                if(!grt(a2,a3) && !grt(a3,a2)){
                        p=0;
                }
                if(!grt(a3,a1) && !grt(a1,a3)){
                        p=0;
                }
                if(p){
                        cout<<"yes\n";
                }
                else{
                        cout<<"no\n";
                }
        }
	return 0;
}
