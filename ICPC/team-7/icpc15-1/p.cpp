#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll N = 1e5+7,mod = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    for(ll q=0;q<t;q++){
        ll n,m;
        cin>>n>>m;
        ll arr[n][m];
        for(ll i=0;i<n;i++)
            for(ll j=0;j<m;j++)
                cin>>arr[i][j];
        //priority_queue<ll> pqr,pqc;
        multiset<ll> mr[n],mc[m];
        for(ll i=0;i<n;i++){
            ll s = 0;
            for(ll j=0;j<m;j++){
                s+= arr[i][j];
                mr[i].insert(s);
            }
        }
        priority_queue<ll> pc[m];
        for(ll i=0;i<m;i++){
            ll s = 0;
            pc[i].push(0);
            for(ll j=0;j<n;j++){
                s+=arr[j][i];
                mc[i].insert(s);
                //cout<<s<<" :: ";
            }
            //cout<<endl;
        }
        //cout<<endl;
        ll ans = mod, ss[m] = {0};
        for(ll i=0;i<n;i++){
            ll s = 0;
            priority_queue<ll> p;
            p.push(0);
            for(ll j=0;j<m;j++){
                ss[j]+=arr[i][j];
                s+=arr[i][j];
                /*p.push(s);
                pc[j].push(ss[j]);*/
                ll a = s-p.top(), b = *(mr[i].begin())-s, c = ss[j]-pc[j].top(), d = *(mc[j].begin())-ss[j];
                //cout<<i<<" "<<j<<" : "<<endl<<s<<" "<<a<<" "<<b<<" "<<c<<" "<<d<<endl<<endl;
                mr[i].erase(s);mc[j].erase(ss[j]);
                p.push(s);
                pc[j].push(ss[j]);
                ans = min(ans, a+b+c+d - arr[i][j]);
                /*if(a==0 && c==0)
                    ans = min(ans, a+b+c+d+arr[i][j]);
                else
                    if(a && c)
                        ans = min(ans, a+b+c+d-arr[i][j]);
                    else
                        ans = min(ans, a+b+c+d);*/
                //cout<<i<<" /// "<<j<<a+b+c+d-arr[i][j]<<endl;
            }
        }
        cout<<ans<<endl;
    }
}
/*
3 3
-2 -3 -2
1 4 3
3 -5 -5
*/