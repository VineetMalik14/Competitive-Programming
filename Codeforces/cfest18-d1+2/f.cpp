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

ll n, k;
vll b(1000000), cnt(1000000);
ll z(){
        ll ans = 0;
        vll a(n-k+1);
        deque<ll> q;
        ll t1=0;
                for(ll i=0; i<k; i++){
                        while(!q.empty() && b[i]>=b[q.back()]){
                                q.pop_back();
                        }
                        q.push_back(i);
                }
                a[t1++]=(b[q.front()]);
                ans+=b[q.front()];
                for(ll i=k; i<n; i++){
                        while(!q.empty() && (q.front()+k<=i)){
                                q.pop_front();
                        }
                        while(!q.empty() && (b[q.back()]<=b[i])){
                                q.pop_back();
                        }
                        q.push_back(i);
                        a[t1++]=(b[q.front()]);
                        ans+=b[q.front()]*(((q.front()-k)/(k-1))+1);
                        ans%=mod;
                }
                return ans%mod;
}
int main(){
        ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

                cin>>n>>k;
                for(ll i=0; i<n; i++){
                        cin>>b[i];
                }
                ll t;
                fol(i,k,n){
                        cnt[i]=cnt[i-1];
                        while(i<=t){
                                cnt[i]++;
                        }
                }
                cout<<z()%mod<<endl;
}