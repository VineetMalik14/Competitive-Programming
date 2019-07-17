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

int main(){
    	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    	ll q; cin>>q;
        ll sz=0;
        vll pr(mox), pl(mox), done(mox), right(mox), left(mox);
        fol(i,1,q+1){
                char ch; ll id; 
                cin>>ch;
                cin>>id;
                if(ch=='R'){
                        sz++;
                        pr[id]=0;
                        pl[id]=sz-1;
                        done[id]=i;
                        right[i]=right[i-1]+1;
                        left[i]=left[i-1];
                }
                else if(ch=='L'){
                        sz++;
                        pr[id]=sz-1;
                        pl[id]=0;
                        done[id]=i;
                        right[i]=right[i-1];
                        left[i]=left[i-1]+1;
                }
                else{
                        ll l1=pl[id]+left[i-1]-left[done[id]];
                        ll r1=pr[id]+right[i-1]-right[done[id]];
                        cout<<min(l1,r1)<<endl;
                        right[i]=right[i-1];
                        left[i]=left[i-1];
                }
        }
    	return 0;
}