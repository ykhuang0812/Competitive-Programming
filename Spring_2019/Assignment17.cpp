#include <bits/stdc++.h>
using namespace std;
#define N 10000004
int t[N];
void update(int x, int d){
    while(x <= N){
        t[x]+=d;
        x+=(x&-x);
    }
}
int sum(int x){
    int s=0;
    while(x>0){
        s+=t[x];
        x-=(x&-x);
    }
    return s;
}
int query(int a, int b){
    if(a > b) swap(a,b);
    return sum(b) - sum(a-1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T,n,q;
    cin >> T;
    while(T--){
        cin >> n >> q;
        for(int i=0;i<=n;i++){
            t[i]=0;
        }
        for(int i=1;i<=n;i++){
            update(i,1);
        }
        for(int i=1;i<=n;i++){
            cout << t[i] << " ";
        }
        cout << "\n";
        while(q--){
            int tt,x;
            cin >> tt >> x;
            if(tt==1){
                update(x,1);    
            }
            else if(tt==2){
                update(x,-(query(x,x)-1));
            }
            else{
                if(sum(N)<x){
                    cout << "endro~!\n";
                    continue;
                }
                int l=0,r=N;
                while(l<r){
                    int m = (r-l)/2+l;
                    if(sum(m)>=x){
                        r=m;
                    }
                    else{
                        l=m+1;
                    }
                }
                cout << r << "\n";
                update(r,-1);
            }
        }
    }
    return 0;
}
