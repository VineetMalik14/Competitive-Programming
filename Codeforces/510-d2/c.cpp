#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod ll(1000000007)
#define mox ll(200005)
#define fol(i,a,b) for(ll i=a; i<b; i++)
#define pb push_back
#define po pop_back
#define mk make_pair
#define vll vector<ll>
#define ff first
#define ss second

int main(){
    	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
        
        ll n; cin>>n;
        vll a(n), pos, neg, z;
        ll p1=0, n1=0, z1=0;
        fol(i,0,n){
                cin>>a[i];
                if(a[i]>0){
                        pos.pb(i);
                        p1++;
                }
                else if(a[i]<0){
                        neg.pb(i);
                        n1++;
                }
                else{
                        z.pb(i);
                        z1++;
                }
        }
        if(n1%2==1){
                ll mi=neg[0];
                vll :: iterator it;
                it = neg.begin();
                fol(i,0,n1){
                        if(a[mi]<a[neg[i]]){
                                mi=neg[i];
                                it=neg.begin()+i;
                        }
                }
                z.pb(mi);
                z1++; n1--;
                neg.erase(it);
        }
        fol(i,1,z1){
                cout<<1<<" "<<z[i]+1<<" "<<z[0]+1<<endl;
        }
        if(z1>0 && (n1>0 || p1>0)){
                cout<<2<<" "<<z[0]+1<<endl;
        }
        if(n1>0){
                fol(i,1,n1){
                        cout<<1<<" "<<neg[i]+1<<" "<<neg[0]+1<<endl;
                }
                fol(i,0,p1){
                        cout<<1<<" "<<pos[i]+1<<" "<<neg[0]+1<<endl;
                }
        }
        else if(p1>0){
                fol(i,1,p1){
                        cout<<1<<" "<<pos[i]+1<<" "<<pos[0]+1<<endl;
                }
                fol(i,0,n1){
                        cout<<1<<" "<<neg[i]+1<<" "<<pos[0]+1<<endl;
                }
        }
    	return 0;
}