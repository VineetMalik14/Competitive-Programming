#include <bits/stdc++.h>
using namespace std;

int main()
{
        freopen("input.txt", "w", stdout);

        long int n=100000, m=1000;
        cout << n << "\n";

        long int temp=1, k=rand()%(n/m) + 1;
        for(long int i=1; i<=n; i++){
                if(i%k != 0){
                        temp=temp+rand()%m;
                }
                cout << temp << " ";
        }
}