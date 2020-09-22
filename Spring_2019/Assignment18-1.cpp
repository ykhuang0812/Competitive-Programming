#include <bits/stdc++.h>
using namespace std;
#define MAXN 100004
int v[MAXN*4],n;

void update(int p, int k, int L=1, int R=n, int x=1){
    if(L==R){
        v[x]=k;
        return;
    }
    int M = (L+R)/2;
    if(p<=M) update(p, k, L, M, x*2);
    else update(p, k, M+1, R, x*2+1);
    v[x] = gcd(v[x*2],v[x*2+1]);
}

int query(int l, int r, int L=1, int R=n, int x=1){
    if(l<=L&&R<=r)return v[x];
    int M = (L+R)/2;
    int a=0,b=0;
    if(l<=M) a = query(l,r,L,M,x*2);
    if(r> M) b = query(l,r,M+1,R,x*2+1);
    if(b) swap(a,b);
    if(b) return gcd(a,b);
    else return a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T,q;
    cin >> T;
    while(T--){
        cin >> n >> q;
        for(int i=1;i<=n;i++){
            update(i,1);
        }
        int op,p,k;
        while(q--){
            cin >> op >> p >> k;
            if(op==1){
                update(p,k);    
            }
            else{
                int l=p,r=MAXN*4-1;
                if(query(p,r)>k){
                    cout << "DOYA!\n";
                    continue;
                }
                while(l<r){
                    int M = (l+r)/2;
                    if(query(p,M)<=k){
                        r=M;
                    }
                    else{
                        l=M+1;
                    }
                }
                cout << r << "\n";
            }
        }
    }

}
