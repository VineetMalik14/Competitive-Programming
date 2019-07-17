#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
#define mod int(1000000007)
#define mox int(200005)
#define fol(i,a,b) for(int i=a; i<b; i++)
#define mk mkae_pair
#define pb push_back
#define po pop_back
#define vint vector<int>
#define ff first
#define ss second

int main(){
	//ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

        //freopen("input.txt", "r", stdin);
        int a[100000];
        set<int> ava;
	int tt; scanf("%d", &tt);
        set<int> :: iterator it;
        while(tt--){
                int n; cin>>n;
                int p1=-1, inf=1, k1;
                fol(i,0,n){
                        scanf("%d", &a[i]);
                        if(a[i]!=-1 && p1==-1){
                                p1=i;
                        }
                }
                if(p1+1){
                        k1=a[p1];
                        fol(i,p1+1,n){
                                k1++;
                                if(a[i]!=k1 && a[i]!=-1){
                                        inf=0;
                                        break;
                                }
                        }
                }
                if(inf){
                        printf("inf\n");
                        continue ;
                }
                ava.clear();
                int k2=a[p1];
                while(k2<k1){
                        ava.insert(k2);
                        k2++;
                }
                int impos=0, t1=a[p1], t2=0, t3=0;
                fol(i,p1+1,n){
                        if(a[i]==a[i-1]+1 || a[i]==-1 || a[i-1]==-1){
                                if(a[i]==a[i-1]+1){
                                        t1=a[i];
                                }
                                else if(a[i]==-1){
                                        t2++;
                                }
                                else{
                                        t3=a[i]-1;
                                        if(t3<=t2){
                                                t2-=t3;
                                                it=ava.begin();
                                                int h1=ava.size(), h2=0;
                                                while(it!=ava.end() && h1>h2){
                                                        int d=*it;
                                                        ++it;
                                                        if(d<t1 || d-t1>t2 || (t2-(d-t1))%(d)!=0){
                                                                int d1=-1;
                                                                if(it!=ava.end()){
                                                                        d1=*it;
                                                                }
                                                                h2++;
                                                                ava.erase(d);
                                                                if(it!=ava.end()){
                                                                        it=ava.find(d1);
                                                                }
                                                        }
                                                }
                                                if(h1==h2){
                                                        impos=1;
                                                        break;
                                                }
                                        }
                                        else{
                                                if(t3-t2!=t1){
                                                        impos=1;
                                                        break;
                                                }
                                        }
                                        t2=0;
                                        t1=a[i];
                                }
                        }
                        else if(a[i]==1){
                                int ans=a[i-1], j=i+1;
                                while(j<n){
                                        if(a[j]!=(j-i)%ans+1){
                                                ans=0;
                                                break;
                                        }
                                }
                                if(ans){
                                        printf("%d\n",ans);
                                        impos=2;
                                        break;
                                }
                                else{
                                        impos=1;
                                        break;
                                }
                        }
                        else{
                                impos=1;
                                break;
                        }
                }
                if(!impos && ava.size()){
                        int an1=*ava.rbegin();
                        fol(k,0,n){
                                if(a[k]>an1){
                                        an1=0;
                                        printf("impossible\n");
                                        break;
                                }
                        }
                        if(an1){
                                printf("%d\n", an1);
                        }
                }
                else if(impos==1){
                        printf("impossible\n");
                }
        }
	return 0;
}