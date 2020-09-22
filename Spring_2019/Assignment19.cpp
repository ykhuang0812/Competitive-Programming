#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll run(ll r, ll c, ll tmp,ll size){
    if(size==1) return tmp;
    ll hs=size/2;
    if(r<=hs && c<=hs){
        return run(r,c,tmp,hs);
    }
    else if(r<=hs && c>hs){
        return run(r,c-hs,tmp+hs*hs,hs);
    }
    else if(r>hs && c<=hs){
        return run(r-hs,c,tmp+hs*hs*2,hs);
    }
    else if(r>hs && c>hs){
        return run(r-hs,c-hs,tmp+hs*hs*3,hs);
    }
}
pair<ll,ll> run2(ll num,ll size,ll tmpr,ll tmpc){
    if(size==1) return {tmpr,tmpc};
    ll hs=size/2;
    if(num<=hs*hs){
        return run2(num,hs,tmpr,tmpc);
    }
    else if(num<=hs*hs*2){
        return run2(num-hs*hs,hs,tmpr,tmpc+hs);
    }
    else if(num<=hs*hs*3){
        return run2(num-hs*hs*2,hs,tmpr+hs,tmpc);
    }
    else{
        return run2(num-hs*hs*3,hs,tmpr+hs,tmpc+hs);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n,q;
        cin >> n >> q;
        while(q--){
            ll op,r,c,num;
            ll s = 1<<n;
            cin >> op;
            if(op==1){
                cin >> r >> c;
                cout << run(r,c,1,s) << "\n";
            }
            else{
                cin >> num;
                pair<ll,ll> res = run2(num,s,1,1);
                cout << res.first << " " << res.second << "\n";
            }
        }
    }
    return 0;
}
