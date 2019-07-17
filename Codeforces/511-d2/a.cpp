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
        ll k=(n-1)/3, a, b, c;
        a=k; b=k; c=k+1;
        k=(n-1)%3;
        if(k>=1){
                a++;
                if(k>1)
                        b++;
        }
        if(k==2 && a%3==0){
                a--;
                b--;
                c+=2;
        }
        else if(k==1 && a%3==0){
                a--;
                c--;
                b+=2;
        }
        else if(k==1 && b%3==0){
                b--;
                a++;
        }
        else if(k==0 && a%3==0){
                a++;
                b++;
                c-=2;
        }
        else if(k==0 && c%3==0){
                c++;
                a--;
        }
        cout<<a<<" "<<b<<" "<<c<<endl;
    	return 0;
}